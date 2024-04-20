Formato dos dados:

No arquivo DadosEntrada.cvs, cada linha contém o nome, o telefone (com prefixo), o curso, e as notas que cada um dos alunos matriculados em uma universidade obteve durante um semestre. 
No exemplo a seguir, observe que os atributos da aluna Maria Oliveira são (555) 123-4567, Direito, 9.0 e 9.3 e estão separados por vírgula:

Maria Oliveira,(555) 123-4567,Direito,9.0,9.3



O que deve ser feito:

O programa a ser construído deve ler dados de cada aluno, identificando o nome e as notas para, a seguir, 
determinar a nota média e a situação final do aluno (APROVADO, caso a nota média seja maior ou igual a 7.0 ou REPROVADO, 
caso a nota média seja menor do que 7.0). 

Por fim, deve ser gerado um arquivo chamado SituacaoFinal.cvs em que cada linha deverá ter o nome do aluno, a nota média 
com duas casas decimais e a situação do aluno. Por exemplo, para a aluna Maria Oliveira, cujas notas foram 9.0 e 9.3, 
deverá ser gravado no arquivo de saída:

Maria Oliveira, 9.15, APROVADO
