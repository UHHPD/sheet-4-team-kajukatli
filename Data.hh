#ifndef DATA_HH
#define DATA_HH
#include <cmath>
#include <vector>
#include <string>

class Data {
 public:
  Data(const std::string& filename);
  
  unsigned int size() const { return m_data.size(); }
  double measurement(int i) const { return m_data[i]; }
  double binCenter(int i) const {return ((binHigh(i)+binLow(i))/2);}
  double binLow(int i) const { return m_bins[i]; }
  double binHigh(int i) const { return m_bins[i+1]; }
  double error(int i) const { return m_errors[i]; }
  
  bool sigma(const Data& in, int n, int i) const{   
    double delY = fabs(in.measurement(i) - m_data[i]);
    double spe = sqrt( pow(m_errors[i],2) + pow(in.error(i),2) );
    if (delY>n*spe)
    { return true;}
    else 
    {return false;}
  }
  
  int checkCompatibility( const Data& in, int n){
    int counter = 0;
    
    for (int i=0; i <in.size(); i++)
    { 
      if (sigma(in,n,i))
      {counter += 1;}
    }
    return counter;
  }
  
  std::vector<double> average( const Data& in, int n)
  {
    std::vector<double> avgy;
    for(int i=0; i<in.size(); i++)
    {
      double w1= 1/ (pow(m_errors[i],2));
      double w2= 1/ (pow(in.error(i),2));
      avgy.push_back(((w1*m_data[i])+(w2*in.measurement(i)))/(w1+w2));      
    }
    return avgy;
  }
      
 private:
  Data() {}  // disallow empty data set
  void assertSizes();
  std::vector<double> m_data;
  std::vector<double> m_bins;
  std::vector<double> m_errors;
};

#endif
