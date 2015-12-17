#include <iostream>
#include <string>
using namespace std;



//this function determines which of two given names is shorter, and returns the length of the shorter word
int determineLength(string a, string b){
    int la = a.length();
    int lb = b.length();
    if (la<lb) return la;
    else return lb;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool operator < (const string& a, string& b)
/*
pre:Expects two string values to compare. The < comparison is overloaded in this function.
post: Returns a true or false value
*/
      {
         int shorter = determineLength(a,b);
         int i;
         for (i=0;i<shorter;i++){
             if(a.at(i)<b.at(i)) return true;
             else if (a.at(i)==b.at(i)) continue;
             else return false;
         }
      }

bool operator > (const string& a, string& b)
/*
pre:Expects two string values to compare. The > comparison is overloaded in this function.
post: Returns a true or false value
*/
      {
         int shorter = determineLength(a,b);
         int i;
         for (i=0;i<shorter;i++){
             if(a.at(i)>b.at(i)) return true;
             else if ((a.at(i))==(b.at(i))) continue;
             else return false;
         }
      }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   


// COMPARISONS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
bool increasing (string a[], int l){
    //checks if all words are in increasing orderstring to 
    string state = "INC";
    int i;
    for(i=0; i< l-1; i++){
        if(a[i]>a[i+1]){
            state = "NOTINC";
            break;
        }
    }
    if(state == "NOTINC") return false;
    else return true;
}

bool decreasing (string a[], int l){
    //checks if all words are in increasing orderstring to 
    string state = "DEC";
    int i;
    for(i=0; i< l-1; i++){
        if(a[i]<a[i+1]){
            state = "NOTDEC";
            break;
        }
    }
    if(state == "NOTDEC") return false;
    else return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 




string compare (string inputArray [], int length){
        if(increasing(inputArray, length))
            return "INCREASING";
        if(decreasing(inputArray, length))
            return "DECREASING";
        if((!increasing(inputArray, length))&&!(decreasing(inputArray, length)))
            return "NEITHER";
}


int main (){
    int numberOfNames;
    //cout<<"Enter the number of names:"<<endl;
    string name;
    cin>>numberOfNames;
    string array [numberOfNames];
    //take in the names
    int i;
    //cout<<"Enter the names:"<<endl;
    for(i = 0; i < numberOfNames; i++){
        cin>>name;
        array[i] = name;
    }
    cout<<compare(array, numberOfNames)<<endl;
    return 0;
}
//check bob and andy, b&a, o&n b&d