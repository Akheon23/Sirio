
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
PC=0.2;%probabilidad de cruce
mutacion=0.003;
MUTEN=0;
X=rand(tamanoPoblacion,Alelos);%Poblacion de 5000 sujetos con 9 cromosomas cada uno
%X=X*(10^(-3));
mejorSujeto=zeros(1,Alelos);
mejordesempeno=2;
mejordesempenoGeneracion=zeros(5000,1);
%se usa rand pra llenarlo de forma aleatoria

F=zeros(tamanoPoblacion,1);%resultado funcion de desempeño  para sujeto i
Seleccion=zeros(tamanoPoblacion,1);
Ftotal=0;%acumula los valores de las funciones de desempeño

generacion=0;

while((generacion<5000) ||(mejorDesempeno< 10^(-15)))
    
   
    generacion=generacion + 1;
%evalua la poblacion en la funcion de desempeño
for i=1:size(X,1)
   % if(ismember(NaN,X(i,:)>0) || ismember( Inf,X(i,:)>0))X(i,:)=zeros(1,9);end
%    X(i,:)=abs( X(i,:));
%    X(i,:)
   F(i) = Cinetica14DMCTe (X(i,:));
   Ftotal=Ftotal + F(i);
      
end  
% for i=1:size(X,1)
%      if(F(i) >2)F(i)=10^(10);end%penalizacion
% end    

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
valorResta=median(F);
for i=1:size(X,1)
    [C, E] = max (Seleccion);
    poblacionNueva(i,:)=X(E,:);
   X(E,:)=X(E,:) - 1;
end 

%%CODIFICACION

poblacionCodificada=zeros(tamanoPoblacion*9,105);
contAlelos=0;

for k=1:tamanoPoblacion
   
    for l=1:Alelos
    
        poblacionCodificada(l+ contAlelos,:)=decimal2Binary(poblacionNueva(k,l));
    end
    contAlelos=contAlelos+9;
end    


%%CRUCE
%numero de sujetos que se cruzaran
cruce=PC*tamanoPoblacion;

%seleccion aleatoria de sujetos a cruzar
progenitor1=zeros(1,Alelos);
progenitor2=zeros(1,Alelos);
primogenito=zeros(cruce*9,105);

%sujetos que  se cruzan
sincruce=zeros(cruce,1);

%seleccion de sujetos para cruzar
   for i=1:cruce
    sujeto1=randi(tamanoPoblacion);
    while(ismember(sujeto1,sincruce))
        sujeto1=randi(tamanoPoblacion);
    end    
    sincruce(i,1)=sujeto1;
      
   end    

%cruce

for i=1:cruce

     progenitor1=sincruce(i,1);
     progenitor2=sincruce(randi(cruce),1);
    
    for j=1:Alelos
        
         %cruce
         A=[poblacionCodificada((progenitor1-1)*9 + j,1)   ,poblacionCodificada((progenitor1-1)*9 + j,2:26),poblacionCodificada((progenitor2-1)*9 + j,27:51),poblacionCodificada((progenitor1-1)*9 + j,52:77),poblacionCodificada((progenitor1-1)*9 + j,78:105)];
         primogenito(i,:)=A;
        
    end    
       
    
     
        
    
      
    
end    

%%NUEVA POBLACION
poblacionCodificada2=zeros(tamanoPoblacion*9,105);

poblacionCodificada2(1:cruce*9,:)=primogenito;

contPos=cruce*9 +1;

for i=1:tamanoPoblacion
    
    
    if(ismember(i,sincruce)<1)
        contPos=contPos+1;     
        poblacionCodificada2(contPos:contPos+8,:)= poblacionCodificada((i-1)*9 +1:(i-1)*9 + 9,:);
        
    end
end


 
%%MUTACION
if(generacion>1 && mejordesempenoGeneracion(generacion)==mejordesempeno)
    MUTEN=MUTEN+1;
end
if(MUTEN>50)
    mutacion=0.3;
    MUTEN=0;
end
mutan=tamanoPoblacion*mutacion;
for i=1:mutan

    sujeto=randi(tamanoPoblacion*9);
    cromosoma=randi(105);
    genMutado=rand();
    if(genMutado >= 0.5)genMutado=1;end
    if(genMutado < 0.5)genMutado=0;end
   poblacionCodificada2(sujeto,cromosoma)=genMutado;
end

if(mutacion>0.03)mutacion=0.03;end

for i=1:tamanoPoblacion
   
    for j=1:Alelos
        
        X(i,j)=binary2Decimal(poblacionCodificada2((i-1)*9 + j,:));
        if( X(i,j) > 10^(4) || X(i,j) < 10^(-15)) X(i,j)=rand(); end
        
    end    
    
end    


generacion
fprintf('\n')
mejordesempenoGeneracion(generacion)
fprintf('\n')
mejordesempeno
fprintf('\n')




end
