clc
clear all
close all

%%criterio finalizacion entrenamiento
errorPermitidoPrueba=0.1;
errorPermitidoEntrenamiento=0.1;

%carga datos
load('C:\Users\lex\Documents\Inteligencia Computacional\datoslistos1iris.mat');
load('C:\Users\lex\Documents\Inteligencia Computacional\datoslistos2iris.mat');

%obtiene tamaño de base de datos
[filas, columnas]= size(Xe);
[filasP, columnasP]= size(Xp);


%numero de iteraciones entrenendo
iteraciones=0; 

%pesos a entrenar
w0=[0;-0.4;0.3;0.5;-0.2];
w1=[-0.7;0.4;0.9;-0.1;0.4];
w2=[0.6;-0.8;0.5;-0.3;0.7];
w3=[0.3;-0.5;-0.6;0.5];

%%paso
paso=0.01;

d1=2;
d11=2;
cont=1;

ErrorPru=1;
ErrorEnt=1;

while(ErrorEnt>0.05 || ErrorPru>0.05)
 %while(cont<1000)    
     
      cont=cont +1;
        iteraciones=iteraciones + 1;
        %%obtiene entrada aleatoria entrenamiento
        i=randi([1,filas],1,1);
        Xi=Xe(i,:);
        Yi=Ye(i);
        
        %%obtiene entrada aleatoria prueba
        ip=randi([1,filasP],1,1);
        Xip=Xp(ip,:);
        Yip=Yp(ip);
        
        %%calculo salida de la red
        
         N0=dot(w0,Xi);
         N1=dot(w1,Xi);
         N2=dot(w2,Xi);
         
         N0=sigmf(N0,[5 1]);
         N1=sigmf(N1,[5 1]);
         N2=sigmf(N2,[5 1]);
         
         Xi2=[N0,N1,N2,1];
         N4=dot(w3,Xi2);   
         %N4=sigmf(N4,[6 0]);
         
        %%calculo el error  capa final
        d1=N4-Yi;
        
        %%Propagacion del error
        d2=(Xi2)*(1-(Xi2'))*(w3*d1);
        
        %%calculo de nuevos pesos
        w3=w3- paso*d1*Xi2';
        w0=w0- paso*d2(1)*Xi';
        w1=w1- paso*d2(2)*Xi';
        w2=w2- paso*d2(3)*Xi';
        
       %d11=abs(d1);
       j=1;
       ContBuena=0;
       while(j<=filas)
            Xj=Xe(j,:);
            Yj=Ye(j);
            N0=dot(w0,Xj);
            N1=dot(w1,Xj);
            N2=dot(w2,Xj);
         
            N0=sigmf(N0,[5 1]);
            N1=sigmf(N1,[5 1]);
            N2=sigmf(N2,[5 1]);
         
            Xj2=[N0,N1,N2,1];
            N4=dot(w3,Xj2);
            if(N4<=0.5)
                Resp=0;
            elseif(N4>0.5&&N4<=1.6)
                Resp=1;
            else
                Resp=2;
            end
            
            if(Resp==Yj)
                ContBuena=ContBuena+1;
            end
            %disp(strcat('Ent La respuesta es = ',num2str(Resp),' ,y lo que debia salir es = ',num2str(Yi)));
            j=j+1;
       end
       ErrorEntAnt=ErrorEnt;
       ErrorEnt=1-(ContBuena/filas);
       disp(strcat('Error de entrenamiento = ',num2str(ErrorEnt)));
       
       j=1;
       ContBuena=0;
       while(j<=filasP)
            Xj=Xp(j,:);
            Yj=Yp(j);
            N0=dot(w0,Xj);
            N1=dot(w1,Xj);
            N2=dot(w2,Xj);
         
            N0=sigmf(N0,[5 1]);
            N1=sigmf(N1,[5 1]);
            N2=sigmf(N2,[5 1]);
         
            Xj2=[N0,N1,N2,1];
            N4=dot(w3,Xj2);
            if(N4<=0.5)
                Resp=0;
            elseif(N4>0.5&&N4<=1.6)
                Resp=1;
            else
                Resp=2;
            end
            
            if(Resp==Yj)
                ContBuena=ContBuena+1;
            end
            %disp(strcat('Pru ErrorEntLa respuesta es = ',num2str(Resp),' ,y lo que debia salir es = ',num2str(Yi)));
            j=j+1;
       end
       ErrorPruAnt=ErrorPru;
       ErrorPru=1-(ContBuena/filasP);
       disp(strcat('Error de prueba = ',num2str(ErrorPru)));
       
       if(ErrorPru<ErrorPruAnt && ErrorEnt<ErrorEntAnt)
           wbolsillo0 = w0;
           wbolsillo1 = w1;
           wbolsillo2 = w2;
           wbolsillo3 = w3;
       end
end
 
