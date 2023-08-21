#include <boost/lexical_cast.hpp>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace boost;
struct Journal
{
      string title;
      vector<string> enteries;
      Journal(const string& title):title(title){};
      void add_entry(const string& entery){
      static int count =1;
      enteries.push_back(lexical_cast<string>(count++)+ ":" + entery);

      }
      // do not add save for this class 

};
struct PersistenceManager {
     static void save (const Journal& j,const string& filename ){
      ofstream ofs (filename);
      for(auto& e:j.enteries){
            ofs << e <<endl;
      }
     }
};

int main()
{
      Journal journal {"Dear Diary"};
      journal.add_entry("I woke up early!");
      journal.add_entry("I got my car oil changed");
      journal.add_entry("I came to university to study ");
      PersistenceManager pm;
      pm.save(journal,"diary.txt");
    getchar();
    return 0;
}
