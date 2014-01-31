function Result = LMS(Xe,Ye,Xp,Yp)
    it=0;
    w=(zeros(size(Xe,2),1))';
    eta=0.01;
    filasEnt= size(Xe,1);
    filasPru= size(Xp,1);
    
    for iter=1:492
    %while e<0.005
        it=it+1;
        disp(strcat('Iteración = ',num2str(it)));
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        ind=randi([1,filasEnt],1,1);
        Xi=Xe(ind,:);
        Yi=Ye(ind);
        e=((Xi*w')-Yi);
        dE=e*Xi;
        w=(w-(eta*dE));
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        disp(strcat('Error = ',num2str(e)));
        disp(strcat('Pesos = ',num2str(w))); 
    end
    
    ContBuena=0;
    for i=1:filasEnt
        Xi=Xe(i,:);
        Yi=Ye(i);
        Neurona=Xi*w';
        if Neurona<=0.5
            Resp=0;
        elseif Neurona>0.5 && Neurona<=1.5
            Resp=1;
        else
            Resp=2;
        end
        
        switch Resp
            case 0
                if Resp==Yi
                   ContBuena=ContBuena+1;
                end
                disp(strcat('La respuesta es = ',num2str(Resp),' ,y lo que debia salir es = ',num2str(Yi)));
            case 1
                if Resp==Yi
                   ContBuena=ContBuena+1;
                end
                disp(strcat('La respuesta es = ',num2str(Resp),' ,y lo que debia salir es = ',num2str(Yi)));
            case 2
                if Resp==Yi
                   ContBuena=ContBuena+1;
                end
                disp(strcat('La respuesta es = ',num2str(Resp),' ,y lo que debia salir es = ',num2str(Yi)));
            otherwise
                disp('Ni idea');
        end
    end
    disp(strcat('El numero de aciertos con entrenamiento fue = ',num2str(ContBuena)));
    
    ContBuena=0;
    for i=1:filasPru
        Xi=Xp(i,:);
        Yi=Yp(i);
        Neurona=Xi*w';
        if Neurona<=0.5
            Resp=0;
        elseif Neurona>0.5 && Neurona<=1.5
            Resp=1;
        else
            Resp=2;
        end
        
        switch Resp
            case 0
                if Resp==Yi
                   ContBuena=ContBuena+1;
                end
                disp(strcat('La respuesta es = ',num2str(Resp),' ,y lo que debia salir es = ',num2str(Yi)));
            case 1
                if Resp==Yi
                   ContBuena=ContBuena+1;
                end
                disp(strcat('La respuesta es = ',num2str(Resp),' ,y lo que debia salir es = ',num2str(Yi)));
            case 2
                if Resp==Yi
                   ContBuena=ContBuena+1;
                end
                disp(strcat('La respuesta es = ',num2str(Resp),' ,y lo que debia salir es = ',num2str(Yi)));
            otherwise
                disp('Ni idea');
        end
    end
    disp(strcat('El numero de aciertos en prueba fue = ',num2str(ContBuena)));
end