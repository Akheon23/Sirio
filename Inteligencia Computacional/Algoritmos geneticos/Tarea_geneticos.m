
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
mejorSujeto=[1,Alelos];
mejorDesempeno=0;
%se usa rand pra llenarlo de forma aleatoria

F=[tamanoPoblacion,1];%resultado funcion de desempeño  para sujeto i
Seleccion=[tamanoPoblacion,1];
Ftotal=0;%acumula los valores de las funciones de desempeño

generacion=0;

while((generacion<5000) ||(mejorDesempeno< 10^(-15)))
    
   
    generacion=generacion + 1;
%evalua la poblacion en la funcion de desempeño
for i=1:size(X,1)
   F(i) = Cinetica14DMCTe (X(i,:));
   Ftotal=Ftotal + F(i);
      
end  

%separa el sujeto que mejor se comporto en la generacion
mejorSujetoGeneracion=X(min(F));
mejordesempenoGeneracion=Cinetica14DMCTe(mejorSujetoGeneracion);

if(mejordesempenoGeneracion < mejordesempeno)
   mejordesempeno= mejordesempenoGeneracion;
   mejorSujeto=mejorSujetoGeneracion
    
end

%halla  porcentaje de reproduccion
for i=1:size(X,1)
  Seleccion(i)=1/((F(i)*tamanoPoblacion)/Ftotal);
end 


%%POBLACION INTERMEDIA
%seleccion de mejores sujetos para poblacion intermedia

poblacionNueva=[tamanoPoblacion,Alelos];

for i=1:size(X,1)
    poblacionNueva(i)=X(max(Seleccion));
    X(max(Seleccion))=X(max(Seleccion)) - 1;
end 

%%CRUCE
%numero de sujetos que se cruzaran
cruce=PC*tamanoPoblacion;

%seleccion aleatoria de sujetos a cruzar
progenitor1=[1,Alelos];
progenitor2=[1,Alelos];
primogenito=[cruce,Alelos];

%sujetos que no se cruzan
sincruce=[tamanoPoblacion - cruce,1];

for i=1:cruce

    sujeto1=randi(tamanoPoblacion);
    sujeto2=randi(tamanoPoblacion);
    
     progenitor1=poblacionNueva(sujeto1);
     progenitor2=poblacionNueva(sujeto2);
     
     %para no pasar a los sujeros que fueron cruzados
    sincruce=[sincruce;sujeto1];
    sincruce=[sincruce;sujeto2];
        
     %cruce
     primogenito(i)= [progenitor1(1,1:4),progenitor1(1,5:9)];
      
    
end    

%%NUEVA POBLACION
X=primogenito;

for i=1:tamanoPoblacion
    if(find(sincruce==i) < 0)
    X=[X;poblacionNueva(i)];
    end
end


%%MUTACION

mutan=tamanoPoblacion*mutacion;
for i=1:mutan

    sujeto=randi(tamanoPoblacion);
    X(sujeto)=X(sujeto)*(rand());
end

end
