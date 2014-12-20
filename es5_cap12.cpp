//Crea una classe time che includa come membri i valori quali ore minuti secondi.
//Scrivi un membro di funzione getTime() che prenda i valori dall'utente, ed una funzione putTime() che mostri il tempo nella forma 12:59:59.
//Aggiungi il controllo degli errori nela funzione getTime() al fine di minimizzare gli errori dell'utente
//Questa funzione richiede ore minuti e secondi separatamente e per ognuno di questi verifica separatamente gli ios error status flag e il corretto range, del tipo le ore vanno da 0 a 23 , minuti e secondi da 0 59.
//Si raccomanda di non inserire questi valori come stringhe ma di inserirli direttamente come interi, questo implica l'impossibilita' di stampare le entries in valori a virgola mobile.
//Nel main usa un loop che ripetitivamente prende un valore dall'utente per poi, terminato l'inserimento stamparlo.

//QUESTO ESERCIZIO SI FOCALIZZA SUL CONTROLLO DEGLI ERRORI

#include <iostream>
using namespace std;

class _time
{
    int hours,minutes,seconds;
	public:
    _time() :hours(0),minutes(0),seconds(0) { } //no values
    _time(int h, int m, int s) 
	     :hours(h),minutes(m),seconds(0) { }

  void getTime();    
  void putTime();

};

void _time::getTime()
{

    
    /////////////////////////////
    //error checking per hours
    ////////////////////////////
    
while(true) 
{
    cout << "\nEnter hours:   ";   
    cin.unsetf(ios::skipws ); // non ignorare lo spazio bianco
    cin >> hours;

  if( hours < 0 && hours > 23 )
     {
	     cout << "\nHours must be between 0 and 23";
	     cin.clear(ios::failbit);
     }
	    
     if( cin.good() )       //se non ci sono errori
     {
        cin.ignore(2,'\n'); // dopo 3 numeri immessi elimina ulteriori elementi
         break;
     }
	     //se ci sono errori
	cin.clear();
	cout << "\nIncorrect input";
	cin.ignore(2, '\n');

} //while
       
//////////////////////////////////
//error checking per minutes
/////////////////////////////////

while(true)
{
cout << "\nEnter minutes: ";
cin.unsetf(ios::skipws ); 
cin >> minutes;

    if( minutes < 0 && minutes >= 59 )
     {
	   cout << "\nMinutes must be between 0 and 59";
	   cin.clear(ios::failbit);
     }
	     
	     
	     if( cin.good() )      
			       {
		             cin.ignore(2,'\n'); 
			     break;
	               }
	cin.clear();
	cout << "\nIncorrect input";
	cin.ignore(2, '\n');

} //while
       

///////////////////////////////
//error checking for seconds
//////////////////////////////
   
while(true)
{

cout << "\nEnter seconds: ";
cin.unsetf(ios::skipws );
cin >> seconds;
if( seconds < 0 && seconds >= 59 )
     {
              cout << "\nSeconds must be between 0 and 23";
	     cin.clear(ios::failbit);

     } 
		    
     if( cin.good() )      
     {
          cin.ignore(2,'\n'); 
          break;
     }
	cin.clear();
	cout << "\nIncorrect input";
	cin.ignore(2, '\n');
}//while	

}

void _time::putTime()
{
     cout << "time -> " << hours << ':' << minutes << ':' << seconds << endl;  
}
int main()
{

_time tm;
char ch;

do
{
cout << "\nEnter time: ";
tm.getTime();
tm.putTime();
cout << "\nInsert another:  "; cin >> ch;


} while(ch == 'y');
return 0;
}
