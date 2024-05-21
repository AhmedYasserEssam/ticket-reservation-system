#pragma once
#include <string>
#include<iostream>
using namespace std;

class Payment {
private:
    string recipientName;
    double amount;
    string paymentDate;
    string paymentType; // Type of payment: Visa, Cash, etc.

public:
    // Constructors
    Payment();
    Payment(const string& recipient, double amt, const string& date, const string& type);

    // Destructor
    ~Payment();

    // Setters
    void setRecipientName(const string& recipient);
    void setAmount(double amt);
    void setPaymentDate(const string& date);
    void setPaymentType(const string& type);

    // Getters
    string getRecipientName() const;
    double getAmount() const;
    string getPaymentDate() const;
    string getPaymentType() const;

    // Function to display payment details
    void display() const;
};
