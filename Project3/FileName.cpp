#include <iostream>
using namespace std;
class Father {
public:

    string name;
    Father(const string& name)
        :name(name) {
    }
    virtual void bring_outName() const
    {
        cout << "���: " << name << endl;
    }
};
class Baby : public Father
{

public:
    string surname;
    Baby(const string& name, const string& surname)
        :Father(name), surname(surname) {
    }
    void bring_outName() const override
    {
        Father::bring_outName();
        cout << "�� �������i: " << surname << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    cout << "����i�� i�'� ������: ";
    string fatherName;
    cin >> fatherName;
    Father* father = new Father(fatherName);
    father->bring_outName();

    cout << "������ i�'� ������: ";
    string babyName;
    cin >> babyName;
    cout << "����I�� �� �������I ������: ";
    string babySurname;
    cin >> babySurname;

    Baby* baby = new Baby(babyName, babySurname);
    baby->bring_outName();

    delete father;
    delete baby;

    return 0;

}
