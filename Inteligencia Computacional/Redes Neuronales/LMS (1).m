function Result = LMS(X,Y)
    it=0;
    w=(zeros(size(X,2),1))';
    eta=0.01;
    filas= size(X,1);
    
    for iter=1:2000
        it=it+1;
        disp(strcat('Iteración = ',num2str(it)));
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        i=randi([1,filas],1,1);
        Xi=X(i,:);
        Yi=Y(i);
        e=((Xi*w')-Yi);
        dE=e*Xi;
        w=(w-(eta*dE));
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        disp(strcat('Error = ',num2str(e)));
        disp(strcat('Pesos = ',num2str(w))); 
    end
end