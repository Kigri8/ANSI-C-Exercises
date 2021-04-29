#include <stdio.h>
typedef struct account {
  char* username;
  double balance;
} acc;
void transfer(acc* from, acc* to, double amount) {
  if (from->balance > amount) {
    to->balance += amount;
    from->balance -= amount;
  }
}
void display(acc x) {
  printf("%s, balance %.2f\n", x.username, x.balance);
}
int main() {
  acc a = {"foo", 225.0};
  acc b = {"bar", 434.0};
  acc* high = (a.balance > b.balance) ? &a : &b;
  acc* low = (a.balance < b.balance) ? &a : &b;
  double dif = high->balance - low->balance;
  transfer(high,low,dif/2);
  display(a);
  display(b);
}
