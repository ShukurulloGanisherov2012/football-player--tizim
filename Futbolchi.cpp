#include<iostream>
#include<vector>
using namespace std;
class Futbolchi{
public:
	string ism;
	string familiya;
	int yil;
	string davlat;
	string klub;
	void show(){
		cout << familiya << " " << ism << " (year - " << yil << ", country - " << davlat << ", club - " << klub << ") \n";
	}
};
int main(){
	vector<Futbolchi> futbolchilar;
	while(true){
		cout << "________________________________________________________________________________________________\n";
		cout << "1.Add     2.Show     3.Search(ism-familiya)     4.Search(club)     5.Update(club)     6.Delete\n\n";
		int a;
		cout << "Tanlang: ";
		cin >> a;
		switch(a){
			case 1:{
				cout << "Siz futbolchi qo'shish menyusini tanladingiz\n\n";

				string name,surname,country,club;
				int year;
				cout << "Yangi futbolchini ismini kiriting: ";
				cin >> name;
				cout << "Yangi futbolchini familiyasini kiriting: ";
				cin >> surname;
				cout << "Yangi futbolchini davlatini kiriting: ";
				cin >> country;
				cout << "Yangi futbolchini klubini kiriting: ";
				cin >> club;
				cout << "Yangi futbolchini yilini kiriting: ";
				cin >> year;

				Futbolchi futbol;
				futbol.ism = name;
				futbol.familiya = surname;
				futbol.yil = year;
				futbol.davlat = country;
				futbol.klub = club;
				futbolchilar.push_back(futbol);
				cout << "Yangi futbolchi qo'shildi\n\n";
				break;
			}
			case 2:{
				cout << "Siz futbolchi ko'rish menyusini tanladingiz\n\n";
				if(futbolchilar.empty()){
					cout << "Birorta futbolchi yo'q\n\n";
				}else{
					for(int i=0;i<futbolchilar.size();i++){
						cout << i+1 << ") ";
						Futbolchi fut = futbolchilar[i];
						fut.show();
					}
				}
				break;
			}
			case 3:{
				cout << "Siz futbolchini ism-familiyasi bo'yicha qidirish menyusini tanladingiz\n\n";
				string n,s;
				cout << "Qidirilayotgan futbolchining ismini kiriting: ";
				cin >> n;
				cout << "Qidirilayotgan futbolchining familiyasini kiriting: ";
				cin >> s;
				int index = -1;
				for(int i=0;i<futbolchilar.size();i++){
					Futbolchi f = futbolchilar[i];
					if(f.ism == n and f.familiya == s){
						index = i;
						break;
					}
				}
				if(index==-1){
					cout << "Bunday futbolchi topilmadi\n";
				}else{
					cout << index + 1 << ") ";
					Futbolchi uzbek = futbolchilar[index];
					uzbek.show();
				}
				break;
			}
			case 4:{
				cout << "Siz futbolchini clubi bo'yicha qidirish menyusini tanladingiz\n\n";
				string c;
				cout << "Qidirilayotgan futbolchining klubini kiriting: ";
				cin >> c;
				int index = -1;
				for(int i=0;i<futbolchilar.size();i++){
					Futbolchi f = futbolchilar[i];
					if(f.klub == c){
						index = i;
				}	break;
					}
				if(index==-1){
					cout << "Bunday futbolchi topilmadi\n";
				}else{
					cout << index + 1 << ") ";
					Futbolchi uzbek = futbolchilar[index];
					uzbek.show();
				}
				break;
			}
			case 5:{
				cout << "Siz futbolchining clubini o'zgartirish menyusini tanladingiz\n\n";
				string name;
				cout << "Qidirilayotgandavlatni nomini kiriting: ";
				cin >> name;
				int index = -1;
				for(int i=0;i<futbolchilar.size();i++){
					Futbolchi d = futbolchilar[i];
					if(d.ism == name){
						index = i;
						break;
					}
				}
				if(futbolchilar.empty()){
					cout << "Ro'yhat to'ldirilmagan\n";
					break;
				}
				if(index==-1){
					cout << "Bunday davlat topilmadi\n";
				}else{
					cout << index+1 << ") ";
					Futbolchi uz = futbolchilar[index];
					uz.show();
					string cl;
					cout << "Ushbu futbolchi klubi qaysi klubga o'zgartirilsin: ";
					cin >> cl;
					futbolchilar[index].ism = cl;
					cout << "Ushbu davlat poytaxti o'zgartirildi!\n";
				}
				break;
			}
			case 6:{
				cout << "Siz futbolchi o'chirish menyusini tanladingiz\n\n";
				string name;
				cout << "Qidirilayotgan futbolchini ismini kiriting: ";
				cin >> name;
				int index = -1;
				for(int i=0;i<futbolchilar.size();i++){
					Futbolchi d = futbolchilar[i];
					if(d.ism == name){
						index = i;
						break;
					}
				}
				if(futbolchilar.empty()){
					cout << "Ro'yhat to'ldirilmagan\n";
					break;
				}
				if(index==-1){
					cout << "Bunday futbolchi topilmadi\n";
				}else{
					Futbolchi k = futbolchilar[index];
					futbolchilar.erase(futbolchilar.begin()+index);
				}
				break;
			}
			default:{
				cout << "Bunday menyu yo'q\n\n";
				break;
			}
		}
	}
	return 0;
}

