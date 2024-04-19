// split2.cpp

#include <algorithm> // find_if()
#include <cctype> // isspace()
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �μ��� ������ ���� true, �׷��� ���� ���� false�� ��ȯ
static bool space(char c)
{
	return isspace(c);
}

// �μ��� ������ ���� false, �׷��� ���� ���� true�� ��ȯ
static bool not_space(char c)
{
	return !isspace(c);
}

static vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = str.begin();

	// for(iter i = str.begin(); i != str.end; i++)
	while (i != str.end()) {
		cout << "String begin pos: " <<distance(str.begin(), i) << endl;

		// ���� ������ ����
		// ���� i ��ġ���� ù ��° ���� �ƴ� ���� ã��
		i = find_if(i, str.end(), not_space);
		cout << "String find pos: " << distance(str.begin(), i) << endl;

		// ���� �ܾ��� ���� ã��
		// while �ݺ��� �� �׻� ���ο� �ݺ��� j�� ����.
		// ���� i ��ġ���� ù ��° ���� ���� ã��
		iter j = find_if(i, str.end(), space);
		cout << "j pos: " << distance(str.begin(), j) << endl;

		// [i, j] ������ ���ڸ� ����
		if (i != str.end())
			ret.push_back(string(i, j));

		// i �ݺ��� ��ġ�� j �ݺ����� ��ġ�� ����.
		i = j;
		cout << "i move pos: " << distance(str.begin(), i) << endl;
	}

	return ret;
}

int main()
{
	string s;

	// ���ڿ��� �� �྿ �Է¹޾� ����
	while (getline(cin, s)) {
		vector<string> v = split(s);

		// ���� v�� ������ �ܾ ���� ���
		for (vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
	}
	return 0;
}