

    #include <string.h>  
    #include<iostream>  
    using namespace std;  
    int main()  
    {  
        int i,ilength;  
        char str1[20];  
        cout << "��J�@�Ӧr��: ";  
        cin >> str1;  
        ilength = strlen(str1);  
        cout << "�Ӥl�ꪺ�ϦV:";  
        for(i = ilength;i>=1;i--){  
            cout << str1[i];  
        }  
        cout << str1[0] << endl;  
    }


