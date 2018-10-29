#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H


namespace sict {
  const int max_name_length = 40;
  const int min_sin = 100000000;
  const int max_sin = 999999999;
  const int max_yrs = 4;

  class CRA_Account
  {
   
    char family_name[max_name_length];
    char given_name[max_name_length];
    int sin;
    int tax[max_yrs] = { 0 };
    double balance[max_yrs] = {};
    int numYears;

  public:
    void set(const char* familyName, const char* givenName, int sin);
    bool isEmpty() const;
    void display() const;
    void set(int year, double balance);


  };
}

#endif