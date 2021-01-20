#include <fstream>
#include <vector>
#include <string>

using std::string;
using std::vector;

struct Passenger {
	short pass_id;
	bool survival;
	short pclass;
	string name;
	string sex;
	float age;
	short sibsp;
	short parch;
	string ticket;
	float fare;
	string cabin;
	char embarked;
};

void replace_all(string& str, const string& to_replace, const string& replace_with)
{
	size_t pos = str.find(to_replace);
	while (pos != string::npos)
	{
		str.replace(pos, to_replace.size(), replace_with);
		pos = str.find(to_replace, pos + replace_with.size());
	}
}

vector<vector<string>> parseCSV(std::istream& out)
{
	string ln;
	string buff;

	vector<string> sep_str;
	vector<vector<string>> res;

	char quote = 0;
	char pos = 0;

	while (getline(out, ln, '\r'))
	{
		pos = 0;
		quote = 0;

		for (char ch : ln)
		{
			if (ch == ',')
			{
				switch (quote)
				{
				case 0:
					sep_str.push_back(buff);
					buff.clear();
					++pos;
					continue;
				case 2:
					sep_str.push_back(buff);
					buff.clear();
					quote = 0;
					++pos;
					continue;
				}
			}
			if (ch == '"')
			{
				switch (quote)
				{
				case 0:
					quote = 1;
					continue;
				case 1:
					quote = 2;
					continue;
				case 2:
					buff.push_back('"');
					quote = 1;
					continue;
				}
			}
			buff.push_back(ch);
		}
		sep_str.push_back(buff);
		buff.clear();

		res.push_back(sep_str);
		sep_str.clear();
	}
	return res;
}

std::istream& operator>> (std::istream& in, std::vector<Passenger>& vector) {
	auto matrix = parseCSV(in);
	matrix.erase(matrix.begin());

	for (auto row : matrix)
	{
		Passenger pass;

		pass.pass_id = std::stoi(row[0]);
		pass.survival = std::stoi(row[1]);
		pass.pclass = std::stoi(row[2]);
		pass.name = row[3];
		pass.sex = row[4];
		pass.age = row[5] == "" ? 0 : std::stof(row[5]);
		pass.sibsp = std::stoi(row[6]);
		pass.parch = std::stoi(row[7]);
		pass.ticket = row[8];
		pass.fare = std::stof(row[9]);
		pass.cabin = row[10];
		pass.embarked = row[11][0];

		vector.push_back(pass);
	}

	return in;
}

std::ostream& operator<< (std::ostream& out, vector<Passenger> vector)
{
	out << "PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Cabin,Embarked" << '\r';

	for (auto& pass : vector)
	{
		string name = pass.name;
		replace_all(name, "\"", "\"\"");

		out << pass.pass_id << ','
			<< pass.survival << ','
			<< short(pass.pclass) << ','
			<< '"' << name << '"' << ','
			<< pass.sex << ','
			<< short(pass.age) << ','
			<< short(pass.sibsp) << ','
			<< short(pass.parch) << ','
			<< pass.ticket << ','
			<< pass.fare << ','
			<< pass.cabin << ','
			<< pass.embarked << '\r';
	}
	return out;
}

void bubbleSort(std::vector<Passenger*>& vector)
{
	int size = vector.size();
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = size - 1; j > i; --j)
		{
			if (vector[j]->age < vector[j - 1]->age)
				std::swap(*vector[j], *vector[j - 1]);
		}
	}
}

int main()
{
	std::ifstream in("train.csv");
	vector<Passenger> passengers;
	vector<Passenger> pass_output;
	vector<Passenger> females_sorted;
	vector<Passenger*> females_sorted_ptr;

	in >> passengers;

	for (auto& item : passengers)
	{
		if (item.pclass == 1 and item.sex == "female" and item.survival)
			females_sorted_ptr.push_back(&item);
	}

	bubbleSort(females_sorted_ptr);

	for (auto& item : females_sorted_ptr)
	{
		pass_output.push_back(*item);
	}

	for (auto& item : passengers)
	{
		if (item.pclass != 1 and !(item.sex == "female" and item.survival))
			pass_output.push_back(item);
	}

	std::ofstream out("out.csv");
	out << pass_output;
}