clc
clear all
close all

    %carga datos
    load('datoslistos1iris.mat');
    load('datoslistos2iris.mat');
    
    %obtiene tamaño de base de datos
    [filas, columnas]= size(Xe);
    [filasP, columnasP]= size(Xp);
    
    %criterios de entrenamiento
    Condicion_parada=0;
    nomejora=0;

    deltapruebaant=2000;
    errorespruebaant=2000;
    deltasalidaant=2000;
    
    %numero de iteraciones entrenendo
    iteraciones=0;
    %pesos a entrenar
    Pesos1=[0.1;0.1;0.1;0.1;0.1];
    Pesos2=[1;0.11;1;0.1;0.1];
    Pesos3=[-1;0.91;-1;1;-0.91];
    Pesos4=[-2;3;1;-7];
    paso=0.001;
    [deltaprueba]=validacion_back_german_1capa_3n(Xp,Yp,Pesos1,Pesos2,Pesos3,Pesos4);
    deltasalida=0;
    while(Condicion_parada<2)
       % paso=0.001;
        iteraciones=iteraciones+1;
        Xrandom=randi([1,filas],1,1);
        Salidarandom=Ye(Xrandom);
        
        neurona1=dot(Pesos1,Xe(Xrandom,:));
        neurona2=dot(Pesos2,Xe(Xrandom,:));
        neurona3=dot(Pesos3,Xe(Xrandom,:));
        
%         neuronaeval1=gaussmf(neurona1,[1 0])
%         neuronaeval1=sigmf(neurona1,[1/200 400]);

        neuronaeval1=sigmf(neurona1,[5 0]);
        neuronaeval2=sigmf(neurona2,[5 0]);
        neuronaeval3=sigmf(neurona3,[5 0]);
        
        salidaprimeracapa=[neuronaeval1 ;neuronaeval2; neuronaeval3;1];
        neurona4=dot(Pesos4,salidaprimeracapa');
        
        deltasalida=neurona4-Salidarandom;
        deltaoculta1=salidaprimeracapa.*(1-salidaprimeracapa).*(deltasalida*Pesos4);
    
        
        Pesos4=Pesos4-(paso.*deltasalida.*salidaprimeracapa);
        Pesos3=Pesos3-(paso.*deltaoculta1(1).*Xe(Xrandom,:)');
        Pesos2=Pesos2-(paso.*deltaoculta1(2).*Xe(Xrandom,:)');
        Pesos1=Pesos1-(paso.*deltaoculta1(3).*Xe(Xrandom,:)');

               
        [deltaprueba]=validacion_back_german_1capa_3n(Xp,Yp,Pesos1,Pesos2,Pesos3,Pesos4);
        
        if(abs(deltaprueba)<abs(deltapruebaant) && abs(deltasalida)<abs(deltasalidaant))
            Pesosbolsillo4=Pesos4;
            Pesosbolsillo3=Pesos3;
            Pesosbolsillo2=Pesos2;
            Pesosbolsillo1=Pesos1;
        end
        deltasalidaant=deltasalida;
        deltapruebaant=deltaprueba;
        
        
        grafica(iteraciones)=deltasalida;
        grafica2(iteraciones)=deltaprueba;
        tiempo(iteraciones)=iteraciones;
        
%         figure(1)
%         subplot(2,1,1)
%         plot(iteraciones,deltasalida,'r')
%         title('deltasalida')
%         xlabel('iteraciones')
%         ylabel('delta')
%     
%         subplot(2,1,2)
%         plot(iteraciones,deltaprueba,'g')   
%         title('deltaprueba')
%         xlabel('iteraciones')
%         ylabel('delta')
        

        
%         if(abs(deltaprueba)<0.1 && abs(deltasalida)<0.1)
%             Condicion_parada=3;
%         end
%         figure(2)
%         subplot(1,2,1)
%         plot(tiempo,grafica,'r')
%         title('deltasalida')
%         xlabel('iteraciones')
%         ylabel('delta')
%     
%         subplot(1,2,2)
%         plot(tiempo,grafica2,'g')   
%         title('deltaprueba')
%         xlabel('iteraciones')
%         ylabel('delta')
        
        
    end
        Pesos4
        Pesos3
        Pesos2
        Pesos1
        [filas3, columnas3]= size(xp);
    cont2=0;
    clasificacionesIncorrectas=0;
     
%     while(cont2<filas3)
%     
%        cont2= cont2 + 1;
%        neurona1=dot(Pesos1,xp(cont2,:));   
%        neurona2=dot(Pesos2,xp(cont2,:));
%        neurona3=dot(Pesos3,xp(cont2,:));
%        
%        neuronaeval1=sigmf(neurona1,[5 0]);
%        neuronaeval2=sigmf(neurona2,[5 0]);
%        neuronaeval3=sigmf(neurona3,[5 0]);
%         
%        salidaprimeracapa=[neuronaeval1 ;neuronaeval2; neuronaeval3;1];
%        neurona4=dot(Pesos4,salidaprimeracapa');
%        
%        tiempo2(cont2)=cont2;
%       grafica10(cont2)=neurona1;
%       grafica20(cont2)=neurona2;
%        grafica30(cont2)=neurona3;
%        grafica40(cont2)=neurona4;
%        
%     
% 
%        
%         if(abs(neurona4)-abs(y(cont2))>0.49)
%             
%          clasificacionesIncorrectas= clasificacionesIncorrectas + 1;   
%             
%         end 
%         
%        
%     end
%     
%     subplot(2,2,1)
%     plot(tiempo2,grafica10,'g')   
%     title('neurona1')
%     xlabel('iteraciones')
%     ylabel('salida neurona1')
%     
%     subplot(2,2,2)
%     plot(tiempo2,grafica20,'r')   
%     title('neurona2')
%     xlabel('iteraciones')
%     ylabel('salida neurona2')
%     
%     subplot(2,2,3)
%     plot(tiempo2,grafica30,'g')   
%     title('neurona3')
%     xlabel('iteraciones')
%     ylabel('salida neurona3')
%     
%     subplot(2,2,4)
%     plot(tiempo2,grafica10,'g')   
%     title('neurona4')
%     xlabel('iteraciones')
%     ylabel('salida neurona4')
%     