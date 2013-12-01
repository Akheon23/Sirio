#include"sTime.hpp"
#include <QDebug>


bool sTime::sGetDate()
{
	date=0;
	time_t current_time;
	char* c_time_string;
	current_time = time(NULL);
	if (current_time == ((time_t)-1))
	{
		return 0;
	}
	c_time_string = ctime(&current_time);
    //cout<<c_time_string<<endl;
	if (c_time_string == NULL)
	{
		return 0;
	}
    	day[0]=c_time_string[0];
	day[1]=c_time_string[1];
	day[2]=c_time_string[2];

	if(day[0]=='M' && day[1]=='o' && day[2]=='n')
		weekday="Lunes";
	else if(day[0]=='T' && day[1]=='u')
		weekday="Martes";
	else if(day[0]=='W')
		weekday="Miercoles";
	else if(day[0]=='T'&& day[1]=='h')
		weekday="Jueves";
	else if(day[0]=='F')
		weekday="Viernes";
	else if(day[0]=='S'&&day[1]=='a')
		weekday="Sabado";
	else if(day[0]=='S'&&day[1]=='u')
		weekday="Domingo";

    	month[0]=c_time_string[4];
	month[1]=c_time_string[5];
	month[2]=c_time_string[6];
	int entero=c_time_string[8];
	if(entero==32)
	{
        //cout<<"es cero"<<endl;
		date=c_time_string[9]-48;

		
	}
	else
	{
        //cout<<" no es cero"<<endl;
		date=(c_time_string[8]-48)*10+c_time_string[9]-48;
	}
	
    //cout<<date<<" dia "<<endl<<c_time_string[8]+1<<"ocho"<<endl<<c_time_string[9]<<"nueve"<<endl;
	datevect[0]=c_time_string[8];
	datevect[1]=c_time_string[9];
	
	hour=(c_time_string[11]-48)*1000+(c_time_string[12]-48)*100+(c_time_string[14]-48)*10+c_time_string[15]-48;
    //cout<<hour<<" hora "<<endl<< " entero "<< entero << endl;
	year=(c_time_string[20]-48)*1000+(c_time_string[21]-48)*100+(c_time_string[22]-48)*10+c_time_string[23]-48;


}

int sTime::sGetTime()
{
	time_t current_time;
	current_time = time(NULL);
    char* c_time_string;
	if (current_time == ((time_t)-1))
	{
		return -1;
	}
	c_time_string = ctime(&current_time);
	if (c_time_string == NULL)
	{
		return -1;
	}
	hour=(c_time_string[11]-48)*1000+(c_time_string[12]-48)*100+(c_time_string[14]-48)*10+c_time_string[15]-48;
	return hour;

}

bool sTime::sTimeTrigger(int period, bool new_base)
{	
	if(new_base==1)
	{
        triggertime=period;
	}
	else
	{
		int diferencia= triggertime-period;
		if(diferencia<=0)
		{
			return 1;
		}
	}
	return 0;

}

bool sTime::sSaveImage(IplImage *Image,unsigned long long index,char* path )
{
	sGetDate();
    //cout<<path<<endl;
	string encabezado,command;
	string fin3=".png";
	stringstream encabezadostr,commandstr;
	
	encabezadostr <<path<<'/'<< month[0] << month[1] << month[2]<<'/'<<weekday<<'_'<<date<< '/'<< index << fin3;

	encabezado=encabezadostr.str();
	encabezadostr.str("");
    //cout<<encabezado.c_str()<<endl;
    //cvSaveImage(encabezado.c_str(),Image);
   
return 0;
}

QString sTime::sQSetPath(QString &a)
{
    sGetDate();
    QString msj;
    msj=a;
    //msj<<a<<'/'<<month<<'/'<<weekday<<'_'<<date;
    msj.append('/');
    msj.append(month[0]);
    msj.append(month[1]);
    msj.append(month[2]);
    //a.append(month[3]);
    msj.append('/');
    msj.append(weekday);
    msj.append('_');
    msj.append(QString("%1").arg((date)));
    msj.append('/');

    qDebug(msj.toStdString().c_str());
    return msj;

}

sTime::sTime()
{
}

sTime::~sTime()
{
}
