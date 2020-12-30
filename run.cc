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

/*int Data :: checkCompatibility(const int n)
{ 
  for (int i = 0; i < size+1; i++)
  {
    
    double mean = (datA.measurement(i)+datB.measurement(i)+datC.measurement(i)+datD.measurement(i))/4;
    cout<< mean<< endl;
    
    double del1_y= abs(datA.measurement(i)-mean);
    double del2_y= abs(datB.measurement(i)-mean);
    double del3_y= abs(datC.measurement(i)-mean);
    double del4_y= abs(datD.measurement(i)-mean);
    
    double sd =sqrt((pow(del1_y,2) +pow(del2_y,2) +pow(del3_y,2) +pow(del4_y,2))/4);
  //cout<<"Standard deviation is:"<<sd<<endl;
  }
    
 return mean; 
}*/


int main() {
  
  using namespace std;
  
  //double del1_y= datA.measurement(27)-datB.measurement(27);
  //cout<< "measurement of difference is:"<< del1_y<< endl;
  

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
  
  cout<< "Average of Exp A and Exp B :" << datA.checkCompatibility(datB,1) << datA.average(datB,1) << endl;
  
  //assertSizes();
  return 0;
}
//void Data::assertSizes() { assert(m_data.size() + 1 == m_bins.size()); }
