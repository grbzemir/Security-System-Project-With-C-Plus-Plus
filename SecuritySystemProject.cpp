#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()

{
   
   system("color 4");

   int secim;
   int i;
   i=0;

   string text;
   string old;
   string sifre1;
   string sifre2;
   string pass;
   string name;
   string sifre0;
   string yas;
   string kullanici;
   string word;
   string word1;

   string creds[3]; // 3 elemanlı bir dizi oluşturduk
   string cp[3]; // 3 elemanlı bir dizi oluşturduk

   cout<<"   Security System Project(GuvenlikProjesi)   "<<endl;

   cout<<"_____________________________________________"<<endl<<endl;
   cout<<"|                  1-REGISTER                |"<<endl;
   cout<<"|                  2-LOGIN                   |"<<endl;
   cout<<"|                  3-CHANGE PASSWORD         |"<<endl;
   cout<<"|__________________4-EXIT____________________|"<<endl;

   do 

   {

    cout<<endl<<endl;
    cout<<"Lutfen Seciminizi Giriniz: ";
    cin>>secim;

    switch(secim)

    {

    case 1:

    {

    cout<<"_____________________________________________"<<endl<<endl;
    cout<<"|-----------------REGISTER-------------------|"<<endl;
    cout<<"|____________________________________________|"<<endl<<endl;

    cout<<"Lutfen Adinizi Giriniz: ";
    cin>>name;
    
    cout<<"Lutfen Sifrenizi Giriniz: ";
    cin>>sifre0;

    cout<<"Lutfen Yasinizi Giriniz: ";
    cin>>yas;

    ofstream of1;
    of1.open("file.txt",ios::app);

    if (of1.is_open())

    {

        of1<<name<<endl;
        of1<<sifre0<<endl;
        cout<<"Kayit Basarili"<<endl;
    
        
    }

    break;
   
    }


    case 2:

    {
   
    i=0;
    
    cout<<"_____________________________________________"<<endl<<endl;
    cout<<"|-----------------LOGIN----------------------|"<<endl;
    cout<<"|____________________________________________|"<<endl<<endl;

 
     ifstream of2;
     of2.open("file.txt",ios::in);

     cout<<"Lutfen Kullanici Adinizi Giriniz: ";
     cin>>kullanici;

     cout<<"Lutfen Sifrenizi Giriniz: ";
     cin>>pass;

     if (of2.is_open())

     {

        while (!of2.eof()) // dosya sonuna gelmedigimiz sürece döndürür!


        {

            while(getline(of2 , text))

            {

                istringstream iss(text); // Öncelikle, "text" stringi "istringstream" tipinde bir nesneye atanır. 
                iss>>word; // iss adıyla tanımlaam yaptık. iss nesnesi üzerinden "word" değişkenine değer atadık.
                creds[i]=word; // creds dizisine word değişkenini atadık.
                i++;

            }

            if(kullanici==creds[0] && pass==creds[1])

            {

                cout<<"----Giris Basarili----";
                cout<<endl<<endl;

                cout<<"Detaylar: "<<endl;

                cout<<"Isim: "<<name<<endl;
                cout<<"Sifre: "<<sifre0<<endl;
                cout<<"Yas: "<<yas<<endl;

            }

            else

            {

                cout<<endl<<endl;
                cout<<"----Giris Basarisiz----";
                cout<<"|      1-GIRIS ICIN 2'YE BASINIZ              |"<<endl;
                cout<<"|      2-SIFRE DEGISIKLIIG ICIN 3'E BASINIZ   |"<<endl;
                 
                break;

                
            }

            
        }
        
     }

     break;

    }

    case 3:

    {

        i=0;

        cout<<"____________________CHANGE PASSWORD_________________"<<endl<<endl;

        ifstream of0;
        of0.open("file.txt",ios::in);
        cout<<"Lutfen Eski Sifrenizi Giriniz: ";
        cin>>old;

        if (of0.is_open())

        {

            while (of0.eof()) // dosya sonuna geldigimizi sürece döndürür!

        {

            while(getline(of0 , text))

            {

                istringstream iss(text); // Öncelikle, "text" stringi "istringstream" tipinde bir nesneye atanır.
                iss>>word1; // iss adıyla tanımlaam yaptık. iss nesnesi üzerinden "word" değişkenine değer atadık.
                cp[i]=word1; // cp dizisine word değişkenini atadık.
                i++;

            }

            if (old==cp[1])

            {

                of0.close();

                ofstream of1;

                if (of1.is_open())

                {

                    cout<<"Yeni Sifrenizi Giriniz: ";
                    cin>>sifre1;
                    cout<<"Yeni Sifrenizi Tekrar Giriniz: ";
                    cin>>sifre2;

                  if(sifre1==sifre2)

                  {

                    of1<<cp[0]<<endl;
                    of1<<sifre1;
                    cout<<"Sifre Girisi Basarili"<<endl;

                  }  

                  else

                  {
                    
                    of1<<cp[0]<<endl;
                    of1<<old;
                    cout<<"Sifre Girisi Basarisiz"<<endl;

                
                  }
                    
                }
                
            }

            else

            {

                cout<<"Lutfen Gecerli Bir Sifre Giriniz"<<endl;
                break;

                
            }
            
        }

    }

    break;

    }

    case 4:

    {


        cout<<"__________________TESEKKURLER!_______________";
        break;

    }

    defalut:
    cout<<"Lutfen Gecerli Bir Secim Giriniz";

    }


   }


   while(secim!=4);

return 0;


}









    
