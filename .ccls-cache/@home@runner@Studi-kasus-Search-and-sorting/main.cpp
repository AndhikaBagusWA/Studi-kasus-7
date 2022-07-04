#include <iostream>

using namespace std;

class data{
public:
void input();
void asc();
void des();
void tukar(string &a, string &b);
void output();
private:
int i,n,j,urut; 
string nama[100], jabatan[100],no_tlp[100],id[100],pil;
};

void data::input(){
  cout<<"Banyak Data Karyawan = ";cin>>n;
  for( i=0;i<n;i++){
    cout<<"Data Karyawan "<<i+1<<endl;
    cout<<"Masukkan ID      : ";cin>>id[i];
    cin.ignore();
    cout<<"Masukkan Nama    : ";getline(cin,nama[i]);
    cout<<"Masukkan Jabatan : ";getline(cin,jabatan[i]);
    cout<<"Masukkan No.Telp : ";cin>>no_tlp[i];
		cout<<endl;
  }
  cout<<"Urutkan ID secara (1. Ascending ) / (2. Descending) : ";cin>>urut;
  switch(urut){
    case 1:
      asc();
    break;
    
    case 2:
      des();
    break;
  }
}

void data::tukar(string &a,string &b ){
	string temp;
	temp = a;
	a = b;
	b = temp;
}

void data::asc(){
	for (i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(id[j]>id[i]){
				tukar(id[j],id[i]);
				tukar(nama[j],nama[i]);
				tukar(jabatan[j],jabatan[i]);
        tukar(no_tlp[j],no_tlp[i]);
				}
		}
	}
}

void data::des(){
	for (i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(id[j]<id[i]){
				tukar(id[j],id[i]);
				tukar(nama[j],nama[i]);
				tukar(jabatan[j],jabatan[i]);
        tukar(no_tlp[j],no_tlp[i]);
			}
		}
  }
}
    
void data::output(){ 
  cout<<"\nData Setelah diurutkan"<<endl;
  cout<<"\nId\t\tNama\t\tJabatan\t\tNomor Telp"<<endl;
  for(j=0; j<n; j++){
    cout<<id[j]<<"\t\t"<<nama[j]<<"\t\t"<<jabatan[j]<<"\t\t"<<no_tlp[j]<<endl;
  }
	cout<<"\nMasukkan pilihan ID : "; cin>>pil;
  for (j=0; j<n; j++){
    if(id[j] == pil){
      cout<<"ID      : "<<id[j]<<endl;
      cout<<"Nama    : "<<nama[j]<<endl;
      cout<<"Jabatan : "<<jabatan[j]<<endl;
      cout<<"No telp : "<<no_tlp[j]<<endl;
    }
  	else if(id[j] != pil){
      cout<<"ID TIDAK DITEMUKAN !!"<<endl;
		}
  }
} 
    
int main(){
  data run;
  run.input();
  run.output();
  return 0;
}