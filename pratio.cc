#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <iomanip>

using namespace std;

fstream infile, outfile;
string f_in  = "PROCAR";
string f_out = "prat";

void fmt()
{
  outfile.setf(ios::scientific, ios::floatfield);
  outfile.setf(ios::right);
  outfile.precision(6);
  outfile.width(14);
}

void skip(int count, string what)
{
  int i;
  string line;

  if (what == "word")
    for (i = 0; i < count; i++)
      infile >> line;

  if (what == "line")
    for (i = 0; i < count; i++)
      getline(infile, line);

}

int main()
{
  int i, j, k, length, index;
  int nkpoints, nbands, nions;
  double energy, suma, sumb;
  double s, p, d;
  double tot;
  double r;
  string word, line;

  infile.open(f_in.c_str(), ios::in);
  outfile.open(f_out.c_str(), ios::out);
  
  //read comment line
  getline(infile, line);

  //get number of k-points, bands, ions
  skip(3, "word");
  infile >> nkpoints;

  skip(3, "word");
  infile >> nbands;

  skip(3, "word");
  infile >> nions;

  cout << nkpoints << endl;
  cout << nbands << endl;
  cout << nions << endl;
  getline(infile, line);

  for (i = 0; i < nkpoints; i++)
  {
    skip(3, "line");
    for (j = 0; j < nbands; j++)
    {
      skip(4, "word"); 
      infile >> energy;
      skip(3, "line");
      suma = 0.0; sumb = 0.0;
      for (k = 0; k < nions; k++)
      {
        infile >> index;
        infile >> s; 
        infile >> p; 
        infile >> d; 
        infile >> tot; 
        getline (infile, line); //jump to next line

//        s = s*s; p = p*p; d = d*d;
//        suma = suma + s + p + d;
//        sumb = sumb + s*s + p*p + d*d;

//        suma = suma + s + p + d;
//        sumb = sumb + s*s + p*p + d*d;
        suma = suma + tot;
        sumb = sumb + tot*tot;
      }
      r = (suma*suma)/(nions*sumb);
   
      skip(2, "line");
      fmt(); outfile << energy;
      fmt(); outfile << r << endl;
    }
    
  }

  infile.close();
  outfile.close();

  return 0;
}
