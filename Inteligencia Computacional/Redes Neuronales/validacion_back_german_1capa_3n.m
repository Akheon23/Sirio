function [delta]= validacion_back_german_1capa_3n(x, y, pesos1, pesos2, pesos3, pesos4)
    
    [filas, columnas]= size(x);
   
    iteraciones=1;
    Condicion_parada=0;
    error=0;
    delta=0;
    while(Condicion_parada<=filas && iteraciones<45)
                
        Salidarandom=y(iteraciones);
        
        neurona1=dot(pesos1,x(iteraciones,:));
        neurona2=dot(pesos2,x(iteraciones,:));
        neurona3=dot(pesos3,x(iteraciones,:));
        
%         neuronaeval1=gaussmf(neurona1,[1 0])
%         neuronaeval1=sigmf(neurona1,[1/200 400]);

        neuronaeval1=sigmf(neurona1,[5 0]);
        neuronaeval2=sigmf(neurona2,[5 0]);
        neuronaeval3=sigmf(neurona3,[5 0]);
        
        salidaprimeracapa=[neuronaeval1; neuronaeval2; neuronaeval3; 1];
        
        neurona4=dot(pesos4,salidaprimeracapa');
        
        delta= neurona4-Salidarandom+delta;
        
        iteraciones=iteraciones+1;
    end
    delta=delta/filas;

end