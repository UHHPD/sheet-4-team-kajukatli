#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>
#include <cassert>

#include "Data.hh"

// generic function comparing two values of some type T used later for int and
// double
template <class T>
bool testEqual(const std::string& name, T expected, T real) {
  if (expected != real) {
    std::cout << "(" << name << ": <" << expected << ">"
              << ", " << real << ") ";
    return false;
  }
  return true;
}

bool testReadingSize() {
  std::cout << "testReadingSize...";
  Data datA("testA");
  return testEqual<int>("size", 1, datA.size());
}

bool testReadingMeasurement() {
  std::cout << "testReadingMeasurement...";
  Data datA("testA");
  return testEqual("measurement", 10., datA.measurement(0));
}

bool testReadingBinEdges() {
  std::cout << "testReadingBinEdges...";
  Data datA("testA");
  return testEqual("bin low", 0., datA.binLow(0)) &&
         testEqual("bin high", 1., datA.binHigh(0));
}

bool testReadingErrors() {
  std::cout << "testReadingErrors...";
  Data datA("testA");
  return testEqual("error", 2., datA.error(0));
}

bool testCopyConstructor() {
  std::cout << "testCopyConstructor...";
  Data a("testA");
  Data b(a);
  Data c = a;  // equivalent to Data c(a)
  return testEqual("measurement", 10., b.measurement(0)) &&
         testEqual("measurement", 10., c.measurement(0));
}

void runTests() {
  std::cout << "running tests...\n";
  std::vector<std::function<bool()> > tests(
      {testReadingSize, testReadingMeasurement, testReadingBinEdges,
       testReadingErrors, testCopyConstructor});
  for (auto test : tests)
    std::cout << (test() ? " ok" : " FAILED!") << std::endl;
}


int main() 
{  
  using namespace std;
  
  cout << "******************************************************" << endl;
  runTests();
  cout << "******************************************************" << endl;
  // create an object which holds data of experiment A
  Data datA("exp_A");
  Data datB("exp_B");
  Data datC("exp_C");
  Data datD("exp_D");
  vector<Data> da;
  
  da.push_back(datA);
  da.push_back(datB);
  da.push_back(datC);
  da.push_back(datD);
  
  // here is the data from experiment A
  cout << "bin 27: from " << datA.binLow(27) << " to " << datA.binHigh(27)
       << endl;
  cout << "bin 27: from " << datB.binLow(27) << " to " << datB.binHigh(27)
       << endl;
  cout << "bin 27: from " << datC.binLow(27) << " to " << datC.binHigh(27)
       << endl;
  cout << "bin 27: from " << datD.binLow(27) << " to " << datD.binHigh(27)
       << endl;
       
       
  cout << "measurement of experiment A in bin 27: " << datA.measurement(27)
       << endl;
  cout << "measurement of experiment B in bin 27: " << datB.measurement(27)
       << endl;
  cout << "measurement of experiment C in bin 27: " << datC.measurement(27)
       << endl;
  cout << "measurement of experiment D in bin 27: " << datD.measurement(27)
       << endl;
       
       
  cout<< "bin 27 of Exp C and Exp D agree within 1*sigma: " << datC.sigma(datD,1,27) << endl;
  cout<< "bin 27 of Exp C and Exp D agree within 2*sigma: " << datC.sigma(datD,2,27) << endl;
  cout<< "bin 27 of Exp C and Exp D agree within 3*sigma: " << datC.sigma(datD,3,27) << endl;
  
  cout<< "Number of bins that deviate 1*sigma for Exp A and Exp B: " << datA.checkCompatibility(datB,1) << endl;
  
  cout<< "Number of bins that deviate 1*sigma for Exp A and Exp C: " << datA.checkCompatibility(datC,1) << endl;
  
  
  cout<< "Number of bins that deviate 1*sigma for Exp A and Exp D: " << datA.checkCompatibility(datD,1) << endl;
  
  
  cout<< "Number of bins that deviate 1*sigma for Exp B and Exp C: " << datB.checkCompatibility(datC,1) << endl;
  
  
  cout<< "Number of bins that deviate 1*sigma for Exp B and Exp D: " << datB.checkCompatibility(datD,1) << endl;
  
  
  cout<< "Number of bins that deviate 1*sigma for Exp C and Exp D: " << datC.checkCompatibility(datD,1) << endl;
  
  //Exercise-2a

  
  cout<< "Number of bins that deviate 2*sigma for Exp A and Exp B: " << datA.checkCompatibility(datB,2) << endl; 
  
  cout<< "\n";
  
  cout<< " The number of datapoints that deviate from 2*sigma is 1 and the maximum number of datapoints that are allowed to deviate from 2*sigma are 3( ~5% of total datapoints) "<< endl;
  
  cout<< "\n";
  
  cout<< "Number of bins that deviate 2*sigma for Exp A and Exp C: " << datA.checkCompatibility(datC,2) << endl;
  
  cout<< "\n";
  
  cout<< " The number of datapoints that deviate from 2*sigma is 1 and the maximum number of datapoints that are allowed to deviate from 2*sigma are 3( ~5% of total datapoints) "<< endl;
  
  cout<< "\n";
  
  cout<< "Number of bins that deviate 2*sigma for Exp A and Exp D: " << datA.checkCompatibility(datD,2) << endl;
  
  cout<< "\n";
  
  cout<< " The number of datapoints that deviate from 2*sigma is 0 and the maximum number of datapoints that are allowed to deviate from 2*sigma are 3( ~5% of total datapoints) "<< endl;
  
  cout<< "\n";
  
  
  cout<< "Number of bins that deviate 2*sigma for Exp B and Exp C: " << datB.checkCompatibility(datC,2) << endl;
  
  cout<< "\n";
  
  cout<< " The number of datapoints that deviate from 2*sigma is 1 and the maximum number of datapoints that are allowed to deviate from 2*sigma are 3( ~5% of total datapoints) "<< endl;
  
  cout<< "\n";
  
  
  cout<< "Number of bins that deviate 2*sigma for Exp B and Exp D: " << datB.checkCompatibility(datD,2) << endl;
  
  cout<< "\n";
  
  cout<< " The number of datapoints that deviate from 2*sigma is 4 and the maximum number of datapoints that are allowed to deviate from 2*sigma are 3( ~5% of total datapoints). "<< endl;
  
  cout<< "\n";
  
  cout<< "Number of bins that deviate 2*sigma for Exp C and Exp D: " << datC.checkCompatibility(datD,2) << endl;
  
  cout<< "\n";
  
  cout<< " The number of datapoints that deviate from 2*sigma is 1 and the maximum number of datapoints that are allowed to deviate from 2*sigma are 3( ~5% of total datapoints). "<< endl;
  
  cout<< "\n";
  //Exercise 2(first subpart):
  /*cout<< "The background is :"  << endl;
  std::vector<double> fu=datA.fun_f();
  for (int i=0; i< fu.size(); i++)
  {
    cout<< fu[i] << "\n";
  }*/
  
 // Exercise 2b
  cout<<"The X^2/ndf of Exp A :" << endl;
  std::vector<double> ch=datA.func_X();
  for (int i=0; i< ch.size(); i++)
  {
    cout<< ch[i]/52 << "\n";
  }
  cout<< "The X^2 distribution for Exp A is a good fit." <<endl; 
  
  cout<< "\n";
  
  cout<<"The X^2/ndf of Exp B :" << endl;
  std::vector<double> ch2=datB.func_X();
  for (int i=0; i< ch2.size(); i++)
  {
    cout<< ch2[i]/52 << "\n";
  }
  cout<< "The X^2 distribution for Exp B is best fit." <<endl;
  
  cout<< "\n";
  
  cout<<"The X^2/ndf of Exp C :" << endl;
  std::vector<double> ch3=datC.func_X();
  for (int i=0; i< ch3.size(); i++)
  {
    cout<< ch3[i]/52 << "\n";
  }
  cout<< "The X^2 distribution for Exp B is a best fit." <<endl;
  
  cout<< "\n";
  
  cout<<"The X^2/ndf of Exp D :" << endl;
  std::vector<double> ch4=datD.func_X();
  for (int i=0; i< ch4.size(); i++)
  {
    cout<< ch4[i]/52 << "\n";
  }
  cout<< "The X^2 distribution for Exp B is a best fit." <<endl;
  
  cout<< "\n";
  //Exercise-2c
  
  Data avgAB = datA.average(datB);
  Data avgCD = datC.average(datD);
  
  Data avgT = avgAB.average(avgCD);
  
  cout<< "The X^2/ndf of combined data set is: " << avgT.func_X()[0]/52.0<<endl;
  
  cout<< "The X^2 distribution for combined data set suggests wrong hypothesis." <<endl;
  
 return 0;
  
}

