


%Evalua la Red
salidaRed=net((DatosInPruebaRed1'));
size(salidaRed)
error=0;%numero de errores


for i=1:size(salidaRed,2)

    if(salidaRed(1,i)>= 0.7)
        salidaRed(1,i)=1;
        
    else
        salidaRed(1,i)=0;
    end
    
    if(salidaRed(1,i)~=DatosOutPruebaRed1(i,1))
        error=error+1;
    end
    
end    

error
errorPorcentaje=(error*100)/1692