#!/bin/bash

# Cores para destaque
RED='\033[1;31m'
GREEN='\033[1;32m'
BLUE='\033[1;34m'
WHITE='\033[1;37m'
YELLOW='\033[1;33m'
MAGENTA='\033[1;35m'
NC='\033[0m'

# Criar arquivos de entrada
echo "linha 1" > test_A.txt
echo "linha 2" >> test_A.txt
echo "linha 3 keyword" >> test_A.txt
echo "linha 4 keyword" >> test_A.txt
echo "linha 5" >> test_A.txt

echo -e "${GREEN}Testes iniciados...${NC}"

# Teste 1: Simples listagem de diretório
echo -e "${GREEN}Teste 1: ${WHITE}test_A.txt "ls -l" "wc -l" test_B.txt ${NC}"
./pipex test_A.txt "ls -l" "wc -l" test_B.txt
cat test_B.txt
echo -e "------------------------------------------------------"
# Teste 2: grep para encontrar linhas com "keyword"
echo -e "${GREEN}Teste 2: ${WHITE}test_A.txt "cat" "grep keyword" test_B.txt ${NC}"
./pipex test_A.txt "cat" "grep keyword" test_B.txt
cat test_B.txt
echo -e "------------------------------------------------------"
# Teste 3: Contar número de linhas do arquivo
echo -e "${GREEN}Teste 3: ${WHITE}test_A.txt "cat" "wc -l" test_B.txt${NC}"
./pipex test_A.txt "cat" "wc -l" test_B.txt
cat test_B.txt
echo -e "------------------------------------------------------"
# Teste 4: Teste de comando inválido
echo -e "${GREEN}Teste 4: ${WHITE}test_A.txt "comando_invalido" "wc -l" test_B.txt $\n${RED}RESULTADO INVALIDO ESPERADO${NC}"
./pipex test_A.txt "comando_invalido" "wc -l" test_B.txt
echo -e "------------------------------------------------------"
# Teste 5: Sleep antes de executar outro comando
echo -e "${GREEN}Teste 5: ${WHITE}test_A.txt "sleep 3" "ls" test_B.txt${NC}"
(time ./pipex test_A.txt "sleep 3" "ls" test_B.txt) 2>&1 | grep real
echo -e "------------------------------------------------------"
# Teste 6: Teste de variáveis de ambiente
echo -e "${GREEN}Teste 6: ${WHITE}test_A.txt "echo \$PATH" "cat" test_B.txt${NC}"
./pipex test_A.txt "echo \$PATH" "cat" test_B.txt
cat test_B.txt
echo -e "------------------------------------------------------"
# Teste 7: Arquivo de entrada inexistente
echo -e "${GREEN}Teste 7: ${WHITE}inexistente.txt "cat" "wc -l" test_B.txt\n${RED}RESULTADO INVALIDO ESPERADO${NC}"
./pipex inexistente.txt "cat" "wc -l" test_B.txt
echo -e "------------------------------------------------------"
# Teste 8: Uso de echo
echo -e "${GREEN}Teste 8: ${WHITE}test_A.txt "echo hello world" "cat" test_B.txt${NC}"
./pipex test_A.txt "echo hello world" "cat" test_B.txt
cat test_B.txt
echo -e "------------------------------------------------------"
# Teste 10: Permissões de arquivo
echo -e "${GREEN}Teste 9: ${WHITE}test_A.txt "cat" "wc -l" test_B.txt${NC}"
chmod -r test_A.txt
./pipex test_A.txt "cat" "wc -l" test_B.txt
chmod +r test_A.txt
echo -e "------------------------------------------------------"
echo -e "${GREEN}Testes concluídos! Verifique os resultados.${NC}"
