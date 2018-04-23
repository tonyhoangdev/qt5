#include <QTextStream>
#include <QDate>
#include <QTime>

int main(void) {

   QTextStream out(stdout);

   QDate dt1(2018, 4, 23);
   out << "The date is " << dt1.toString() << endl;

   QDate dt2;
   dt2.setDate(2018, 3, 3);
   out << "The date is " << dt2.toString() << endl;

   QTime tm1(17, 30, 12, 44);
   out << "The time is " << tm1.toString("hh:mm:ss.zzz") << endl;

   QTime tm2;
   tm2.setHMS(12, 52, 34, 123);
   out << "The time is " << tm2.toString("hh:mm:ss.zzz") << endl;

   return 0;
}
