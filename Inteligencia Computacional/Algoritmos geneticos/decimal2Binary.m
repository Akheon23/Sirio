%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%convert an integer (fractional or not) in a binary  vector
% Autor: Alexander Gomez Villa
% email: alviurlex@gmail.com
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Result b is a row vector of size 111 the firts number is the sign,
% from 2 to 56 it's the integer part and from 57 to 111 it's the frac-
% tional part.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function b= decimal2Binary(x)

    signBit=1;
    %split integer an decimal part
    
      if(x < 0)%if it's a negative number
          x=abs(x);
          signBit=0;
      end
     integ=floor(x);%integer
     fract=x-integ;%fraction

     %integer convertion
    
     integVector=dec2binvec(integ);
     integVector=integVector(end:-1:1);
     integVector=[zeros(1,52- size(integVector,2)) integVector];
     
     %fractional convertion
     fractVector=zeros(1,52);
     i=0;%counter
     
     while( i<52 && fract~=0)
        
         i=i + 1;%counter + 1
         fract=fract*2;
         integF=floor(fract);
         fract=fract-integF;
         fractVector(1,i)=integF;
                           
     end    

    b=[signBit integVector fractVector ];%answer

end