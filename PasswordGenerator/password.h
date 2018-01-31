#ifndef PASSWORD_H_
#define PASSWORD_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>

#define REP(i, n) for(int i=0; i<n; i++)

using std::string;
using std::cout;
using std::cin;

class PasswordGenerator{
private:
	enum { n = 4};
	bool * passwordSettings;
	string password;
	int length;
public:
	PasswordGenerator();
	~PasswordGenerator();

	void Generate();
	void Settings();
	const void Show();

protected:
	void setSettings(const char);

	string checked(bool);
	string passwordStrength();

	const int random(int);

	bool upperInPass();
	bool lowerInPass();
	bool numInPass();
	bool symbolInPass();
};

#endif