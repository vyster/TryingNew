#include <iostream>
using namespace std;
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* start = &arr[0]; cout<< *start<<endl;
    int* end = &arr[4];
    cout<<end-start<<endl;
    cout<<&end-&start<<endl;
    //int* end = &arr[4];
    // double arr1[] = {10.9, 20.3, 30.4, 40.5, 50.5};
    // double* startd = &arr1[0]; 
    // cout<<&arr1[0]<<endl;
    // cout << "Difference in bytes (startd - start): " << ((char*)startd - (char*)start) << " bytes" << endl;
    // cout << "Difference in double (startd - start): " ;std::cout << (startd - (double*)start)  << " bytes" << endl;
    // cout << "Difference in int (startd - start): " ;std::cout << ((int*)startd - start) << " bytes" << endl;

    unsigned int obj = 0xfffde096;
	unsigned char* t1 = (unsigned char*) & obj;
	for (unsigned int i = 0;i < sizeof(obj);i++)
	{
		std::cout << std::hex<<(unsigned)*t1 << std::endl;
		t1++;
	}
}
