function [z] = ag_kNN(x)

global labelTest
global matTreino 
global matTeste

t = length (x);


ci = 1 ;
for i = 1 : t
    if (x(i) == 1)
        matN(:,ci) = matTreino(:,i);
        matT2(:,ci) = matTeste(:,i);
        ci = ci + 1 ;
    end
end

Mdl = fitcknn(matN,labelTest,'NumNeighbors',3,'Standardize',1) ;
[label,score,cost] = predict(Mdl,matT2) ;
[C,order] = confusionmat(label,labelTest) ;
fitness = sum(diag(C)) / 1000 ;


z = 1.0 - fitness ;

end