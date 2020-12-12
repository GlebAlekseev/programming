#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_factorization(unsigned int n) {
    vector<int> nums;
    unsigned int a = n;
    bool go = true;


    int i = 1;
    if (a != 1)
    {
        i++;
    }
    while (go)
    {
        if (a % i == 0)
        {
            nums.push_back(i);
            a = a / i;
        }
        else {
            i++;
        }
        if (a == 1)
        {
            break;
        }
        //Чтобы выйти из цикла  go = false
       /* i++;*/
    }
    int count = 1;/// 3 3 3 37
    unsigned int templast = -1000;
    int zvezd = 0;
    for (int i = 0; i < nums.size()-1; i++)
    {

              //group

        if (nums[i] == nums[i + 1])
        {
            if (i == 0)
            {
                zvezd = 1;
            }
            count++;
        }
        if (count != 1 && nums[i] != nums[i + 1])
        {
            if (zvezd) {


                cout << nums[i] << "^" << count;
                zvezd = 0;
            }
            else {
                cout << "*" << nums[i] << "^" << count;
            }

            count = 1;
        }
        //solo
        if (templast != nums[i] && nums[i] != nums[i+1] && i != 0) // solo middle
        {
            cout << "*" << nums[i];
        }
        
        if (nums[i] != nums[i+1] && i == 0) //solo start
        {
            cout << nums[i];
        }

                
        if (nums[i] != nums[i+1] && i == nums.size() - 2) // solo finish
        {
            cout << "*" << nums[i+1];
        }
  



        templast = nums[i];
    }
}
int main(){

    unsigned int n;
    cin >> n;
    print_factorization(n);
}