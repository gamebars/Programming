#include <iostream>
#include <string>
#include <iomanip>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>

using namespace httplib;
using json = nlohmann::json;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

const string replacerfull = "{webhooks_list}";
const string replacerone = "{Webhook URL}";
const string OneWebhookTemplate = u8R"(
<div class="form-row align-items-center">
    <div class="col">
        <input type="text" value="{Webhook URL}" class="form-control mb-2" disabled>
    </div>
    <div class="col">
        <button type="submit" name="del" value="{Webhook URL}" class="btn btn-danger mb-2">Удалить</button>
    </div>
</div>)";

ofstream logger("log.txt");

json config;

json config_open()
{
    ifstream config_cache("config.json");
    json config;
    logger << u8"Попытка открыть конфигурационный файл" << endl;
    if (config_cache.is_open())
    {
        config_cache >> config;
        logger << u8"Конфигурационный файл десериализирован" << endl;
    }
    else
    {
        logger << u8"Не удалость открыть конфигурационный файл" << endl;
        config["webhooks"] = json::array();
        logger << u8"Был создан json с пустым массивом" << endl;    
    }

    return config;
}

void save_config(json config)
{
    ofstream config_cache("config.json");

    if (config_cache.is_open())
    {
        config_cache << config.dump(4);
        config_cache.close();
        logger << u8"Конфигурационный файл успешно обновлён" << endl;
    }
    else
    {
        logger << u8"Не удалось открыть конфигурационный файл" << endl;
    }
}

string gen_webhook_page()
{
    string webhooks_template, AllWebHooks;
    ifstream webhooks_cache("webhooks_template.html");

    if (webhooks_cache.is_open())
    {
        getline(webhooks_cache, webhooks_template, '\0');
        webhooks_cache.close();
    }
    else
    {
        logger << u8"Не удалось открыть шаблон сайта" << endl;
        return "";
    }

    if (config.empty())
    {
        config = config_open();
    }

    int size = config["webhooks"].size();
    if (size)
    {
        for (int i = 0; i < size; i++)
        {
            string site = config["webhooks"][i];
            string OneWebhook = OneWebhookTemplate;
            OneWebhook.replace(OneWebhook.find(replacerone), replacerone.length(), site);
            OneWebhook.replace(OneWebhook.find(replacerone), replacerone.length(), site);
            AllWebHooks = AllWebHooks + OneWebhook;
        }
        webhooks_template.replace(webhooks_template.find(replacerfull), replacerfull.length(), AllWebHooks);
    }
    else
    {
        webhooks_template.replace(webhooks_template.find(replacerfull), replacerfull.length(), "");
    }
    return webhooks_template;
}

void webhooks_post_resp(const Request& req, Response& res)
{
    if (config.empty())
    {
        config = config_open();
    }

    if (req.has_param("del"))
    {
        string webhook_to_remove = req.get_param_value("del");
        int size = config["webhooks"].size();
        for (int i = 0; i < size; i++)
        {
            string webhook = config["webhooks"][i];
            if (webhook == webhook_to_remove)
            {
                config["webhooks"].erase(config["webhooks"].begin() + i);
                logger << u8"Был удалён вебхук " << webhook << endl;
                break;
            }
        }
    }
    else if (req.has_param("set"))
    {
        string webhook_to_add = req.get_param_value("set");
        if (webhook_to_add == "")
        {
            logger << u8"Получен запрос на добавление пустого вебхука" << endl;
        }
        else
        {
            logger << u8"Получен запрос на добавление вебхука " << webhook_to_add << endl;
            int size = config["webhooks"].size();
            bool existence = false;
            if (size)
            {
                for (int i = 0; i < size; i++)
                {
                    string webhook = config["webhooks"][i];
                    if (webhook == webhook_to_add)
                    {
                        logger << u8"Этот вебхук уже существует" << webhook << endl;
                        existence = true;
                        break;
                    }
                }
            }
            if (!existence)
            {
                logger << u8"Был добавлен вебхук " << webhook_to_add << endl;
                config["webhooks"].push_back(webhook_to_add);
            }
        }
    }
    save_config(config);
    string output = gen_webhook_page();
    res.set_content(output, "text/html; charset=UTF-8");
}

void webhooks_page(const Request& req, Response& res)
{
    string output = gen_webhook_page();
    res.set_content(output, "text/html");
}


int main()
{
    Server svr;
    svr.Post("/webhooks", webhooks_post_resp);
    svr.Get("/webhooks", webhooks_page);
    logger << u8"Сервер успешно запущен" << endl;
    svr.listen("localhost", 1234);
}