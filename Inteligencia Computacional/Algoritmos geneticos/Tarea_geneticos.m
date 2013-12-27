
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Tarea algoritmos geneticos
% Autor: Alexander Gomez Villa - German Diez Valencia
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear
close all
clc


%%Poblacion
tamanoPoblacion=5000;
Alelos=9;
PC=0.5;%probabilidad de cruce
mutacion=0.03;
X=rand(tamanoPoblacion,Alelos);%Poblacion de 5000 sujetos con 9 cromosomas cada uno
%X=X*(10^(-3));
mejorSujeto=zeros(1,Alelos);
mejordesempeno=2;
mejordesempenoGeneracion=zeros(5000,1);
%se usa rand pra llenarlo de forma aleatoria

F=zeros(tamanoPoblacion,1);%resultado funcion de desempe�o  para sujeto i
Seleccion=zeros(tamanoPoblacion,1);
Ftotal=0;%acumula los valores de las funciones de desempe�o

generacion=0;

while((generacion<5000) ||(mejorDesempeno< 10^(-15)))
    
   
    generacion=generacion + 1;
%evalua la poblacion en la funcion de desempe�o
for i=1:size(X,1)
   F(i) = Cinetica14DMCTe (X(i,:));
   Ftotal=Ftotal + F(i);
      
end  

%separa el sujeto que mejor se comporto en la generacion
[C, E] = min (F);

mejorSujetoGeneracion=X(E,:);
mejordesempenoGeneracion(generacion)=Cinetica14DMCTe(mejorSujetoGeneracion);

if(mejordesempenoGeneracion(generacion) < mejordesempeno)
   mejordesempeno= mejordesempenoGeneracion(generacion);
   mejorSujeto=mejorSujetoGeneracion;
    
end

%halla  porcentaje de reproduccion
Seleccion=[tamanoPoblacion,1];
for i=1:size(X,1)
  Seleccion(i)=1/((F(i)*tamanoPoblacion)/Ftotal);
end 


%%POBLACION INTERMEDIA
%seleccion de mejores sujetos para poblacion intermedia

poblacionNueva=zeros(tamanoPoblacion,Alelos);

for i=1:size(X,1)
    [C, E] = max (Seleccion);
    poblacionNueva(i)=X(E);
   X(E,:)=X(E,:) - 1;
end 

%%CRUCE
%numero de sujetos que se cruzaran
cruce=PC*tamanoPoblacion;

%seleccion aleatoria de sujetos a cruzar
progenitor1=zeros(1,Alelos);
progenitor2=zeros(1,Alelos);
primogenito=zeros(cruce,Alelos);

%sujetos que no se cruzan
sincruce=zeros(cruce,1);

%para no pasar a los sujeros que fueron cruzados
      
for i=1:cruce
    sujeto1=randi(tamanoPoblacion);
    while(ismember(sujeto1,sincruce))
        sujeto1=randi(tamanoPoblacion);
    end    
    sincruce(i,1)=sujeto1;
      
end    

for i=1:cruce

       
     progenitor1=poblacionNueva(sincruce(i,1),:);
     progenitor2=poblacionNueva(sincruce(randi(cruce),1),:);
     
        
     %cruce
     A=[progenitor1(1,1:4),progenitor2(1,5:9)];
     primogenito(i,:)=A;
      
    
end    

%%NUEVA POBLACION
X=primogenito;

for i=1:tamanoPoblacion
    if(ismember(i,sincruce)<1)
    X=[X;poblacionNueva(i,:)];
    end
end


%%MUTACION

mutan=tamanoPoblacion*mutacion;
for i=1:mutan

    sujeto=randi(tamanoPoblacion);
    X(sujeto)=X(sujeto)*(randi(tamanoPoblacion)) + 1;
end


generacion
fprintf('\n')
mejordesempenoGeneracion(generacion)
fprintf('\n')
mejordesempeno
fprintf('\n')




end
