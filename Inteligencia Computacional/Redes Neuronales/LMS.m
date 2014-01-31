function  LMS( nombreBaseDatos ,paso,errorEntrenamiento,errorPorcentaje)

%LMS Summary of this function goes here
%   Detailed explanation goes here
%
%% SE CARGA LA BASE DE DATOS
load(nombreBaseDatos);
%% SE CARGA UN VECTOR W CON LOS PESOS(OJO GARANTIZAR QUE LAS FILAS DEL VECTOR W SEAN IGUAL A LA CANTIDAD DE COLUMNAS DEL VECTOR X %% )
%w = load('pesos.mat');
w1=[1 0.5 0.5 0.5 0.5];
%% CREAMOS UNA VARIABLE PARA ALMACENAR EL TAMAÑO DE LA SALIDA DE ENTRENAMIENTO
tamDatosEntrenamiento=size(Ye,1);
%tamDatosEntrenamiento=tamDatosEntrenamiento(1);
%% CREAMOS UN INDICE RANDOM PARA ALEATORIZAR LAS ENTRADAS  Y LAS SALIDAS
indRandXe=int8(randperm(size(Xe,1)));
XeRandom1=Xe(indRandXe,:);
YeRandom1=Ye(indRandXe,:);
%% CREAMOS VECTOR FILA PARA ERROR DE ENTRENAMIENTO EN LA NEURONA
errEntrenaiento=0;

%% CREAMOS VECTORES DE ERRORES DE PRUEBA
tamDatosPrueba=size(Yp,1);


%% guardo el primer w y creo variables para almacenar el error porcentual tanto de entrenamiento como prueba
wbolcillo1=w1;
porcentajeEntrenamiento=0;
porcentajeEntrenamientobolcillo=100;
porcentajePrueba=0;
porcentajePruebabolcillo=100;

%% HACEMOS UN BUCLE INFINITO PARA LA NEURONA 1
bandera=0;
iterador=0;
    while bandera==0
        iterador=iterador+1;
        Aciertos = 0;
        AciertosPrueba=0;
        %% ESCOGEMOS UN Xi RANDOM DE LA MATRIZ RANDOM QUE YA TENIAMOS
        r =randi(size(indRandXe));
        %% CALCULAMOS g(W,Xi)
        g1=dot(w1',XeRandom1(r,:));
        %% CALCULAMOS EL ERROR e=g-Yp(i)        
        errEntrenaiento(1)=g1-YeRandom1(r,:);
        %% CALCULO LOS NUEVOS PESOS
        w1=w1-paso*errEntrenaiento*XeRandom1(r,:);
        %% CONDICION DE PARADA
        % SACAMOS EL ERROR CON LOS DATOS DE ENTRENAMIENTO 
        for p = 1:tamDatosEntrenamiento
            g11 = dot(w1',Xe(p,:));
            if (abs(g11 - Ye(p)) < errorEntrenamiento)
                Aciertos = Aciertos + 1;
            end 
        end
        
        if (iterador>450)
            bandera=1;%(100*(tamDatosEntrenamiento - Aciertos)/tamDatosEntrenamiento)<errorPorcentaje
        end
        %% ERROR PRUEBA
        for p = 1:tamDatosPrueba
            gp11 = dot(w1',Xp(p,:));
            if (abs(gp11 - Yp(p)) < errorEntrenamiento)
                AciertosPrueba = AciertosPrueba + 1;
            end 
        end
        %% CALCULAMOS LOS PORCENTAJES DE ERROR DE ENTRENAMIENTO Y DE PRUEBA
        porcentajeEntrenamiento=(100*(tamDatosEntrenamiento - Aciertos)/tamDatosEntrenamiento);
        porcentajePrueba=(100*(tamDatosPrueba - AciertosPrueba)/tamDatosPrueba);
        %% GRAFICAMOS EL ERROR DE ENTRENAMIENTO
        %plot();plot(error(:,1),'.','Color','red');
        figure(1)
        plot(iterador,Aciertos,'.','Color','red');
        hold on
        plot(iterador,AciertosPrueba,'.','Color','blue');
        if  porcentajePrueba<=porcentajePruebabolcillo && porcentajeEntrenamiento<=porcentajeEntrenamientobolcillo
            porcentajePruebabolcillo=porcentajePrueba;
            porcentajeEntrenamientobolcillo=porcentajeEntrenamiento;
            wbolcillo1=w1
            iterador            
        end
        
    end%end while
    
end%end main for

