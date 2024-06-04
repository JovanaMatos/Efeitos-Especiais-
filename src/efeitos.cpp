#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

void clear_screen() { //limpa ecrã
#if defined(_linux) || defined(FreeBSD) || defined(APPLE_)
    system("clear");
#elif _WIN32
    system("cls");
#else
    cout << "Não apaga..." << endl;
#endif
}


void pause() {// Função para pausar
    #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
        cout << "Pressione ENTER para continuar..." << endl;
        system("read -s -n 1");
    #elif _WIN32
        system("pause>nul|set/p='Pressione ENTER para continuar...");
    #else
        cout << "Pressione ENTER para continuar...";
        string str;
        getline(cin, str);
    #endif
}


void efeito1(string palavra)
{ // Efeito 1- Diagonal Esquerda
  for (auto i = 0; i < palavra.size(); i += 1)
  {
    cout << string(i, ' ') << ' ' << palavra[i] << endl;
  }
}


void efeito2(string palavra)
{ // Efeito 2 - Diagonal Esquerda, Texto Invertido
  for (auto i = 0; i < palavra.size(); i += 1)
  {
    string linhaInvertida(palavra.rbegin(), palavra.rend());
    cout << string(i, ' ') << linhaInvertida[i] << endl;
  }
}


void efeito3(string palavra)
{					// Efeito 3 - Efeito 3 - Diagonais Cruzadas...
  for (int row = 0; row < palavra.size(); row++) // Loop linhas
  {
    for (int column = 0; column < palavra.size(); column++) // Loop colunas
    {
      if (row == column || row + column == palavra.size() - 1) // Verifica se estamos na diagonal principal ou na diagonal secundária
      {
        cout << palavra[row]; // Se sim, imprime o caractere correspondente à palavra atual
      }
      else
      {
        cout << " "; // Caso contrário, imprime um espaço em branco
      }
    } // FIM Loop Colunas
    cout << "\n";
  } // FIM LOOP Linhas
} // FIM efeito 3


void efeito4(string palavra)
{															 // Efeito 4 - Efeito 4 - Diagonal Direita, Palavras por Ordem Inversa...
  int encontrarEspacos = palavra.find(' ');					 // Encontra a posição do primeiro espaço na string 'palavra'
  string primeiroNome = palavra.substr(0, encontrarEspacos); // Extrai o primeiro nome da string 'palavra' usando 'substr'
  string sobrenome = palavra.substr(encontrarEspacos + 1);	 // Extrai o sobrenome da string 'palavra' usando 'substr'
  string ordemInversa = sobrenome + ' ' + primeiroNome;	 // Cria uma nova string com a ordem inversa do sobrenome e primeiro nome, separados por um espaço
  for (int i = ordemInversa.size() - 1; i >= 0; i -= 1)	 // Loop para imprimir a string 'ordemInversa' invertida verticalmente
  {
    string ordemInversaFinal(ordemInversa.rbegin(), ordemInversa.rend()); // Cria uma nova string invertida usando iteradores reversos (rbegin e rend) e armazena em 'ordemInversaFinal'
    cout << string(i, ' ') << ordemInversaFinal[i] << endl;				  // Imprime a string invertida 'ordemInversaFinal' com um número crescente de espaços antes de cada caractere
  }
} // FIM efeito 4


void efeito5 (string palavra)
{ // Efeito 5 - Em V...
  string palavraInvertido(palavra.rbegin(), palavra.rend());
  for (int i = 0; i < palavra.length(); ++i)
  {
    cout << string(i, ' ');								   // Imprime i espaços em branco
    cout << palavra[i];									   // Imprime o caractere da linha atual
    cout << string(palavra.length() * 2 - 2 * (i + 1), ' '); // Imprime espaços no meio
    cout << palavraInvertido[i];							   // Imprime o caractere correspondente do nome invertido
    cout << "\n";
  } // Fim For Loop
} // FIM Efeito 5


void efeito6(string palavra,int veloEfeito6){
  // Efeito 6 -  Deslizante.
    int velocidade = static_cast<int>(veloEfeito6); //CONVERTE PARA INTEIRO

    const int comprimentoLinha = 40;  // numero do tamanho da linha
    string linha = string(comprimentoLinha, ' '); // Definindo tamanho da linha com espaços

    for (int i = 0; i < palavra.size(); i += 1) {
        linha[i] = palavra[i]; // atribuindo o texto a linha
    }
    string ultimaPosição = " ";
    while (true) {
        ultimaPosição = linha[linha.size()-1]; // Armazena última posição
        for (int i = linha.size() - 1; i > 0; i -= 1) {  // desloca para direita
            linha[i] = linha[i-1]; // atribuindo a penultima
        }
        linha[0] = ultimaPosição[0];  //define última posição para primeira
        cout << linha << "\r";
        sleep_for(milliseconds(velocidade));  //sleep_for(milliseconds(150));
       }
}// FIM Efeito 6


int main(int argc, char* argv[]){
    double veloEfeito6 = 0.50 * 1000; // valor padrão
    string palavra = "Jovana Philippe"; // valor padrão


    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-i" && i + 2 < argc) { // Verifica se o próximo argumento é um valor válido para a opção "-i"
            veloEfeito6 = stod(argv[i + 1]) * 1000; // convertendo para milissegundos
            palavra = argv[i + 2];
            break; // sai do loop após processar a opção "-i"
        }
        else if( i + 1 == argc){
            palavra = argv[i];
            break;// sai do loop após processar a opção "-i"
        }
    }

    while (true)
    {
      cout << "****************************************************" << endl;
      cout << "*                                                  *" << endl;
      cout << "*                   EFEITOS                        *" << endl;
      cout << "*                                                  *" << endl;
      cout << "* 1 - Diagonal Esquerda                            *" << endl;
      cout << "* 2 - Diagonal Esquerda, Texto Invertido           *" << endl;
      cout << "* 3 - Diagonais Cruzadas                           *" << endl;
      cout << "* 4 - Diagonal Direita, Palavras por Ordem Inversa *" << endl;
      cout << "* 5 - Em V                                         *" << endl;
      cout << "* 6 - Deslizante                                   *" << endl;
      cout << "* T - Todos                                        *" << endl;
      cout << "* E - Encerrar                                     *" << endl;
      cout << "*                                                  *" << endl;
      cout << "****************************************************" << endl;

      cout << "Escolha uma opcao: ";
      char opcao;
      cin >> opcao;
      opcao = toupper(opcao); // função altera para maiuscula

      clear_screen(); // limpa tela


      if (opcao == 'E'){
          cout << "Encerrando o programa..." << endl;
          break;
        }


      switch (opcao)
      {

      case '1':

          efeito1(palavra);
          cout<<"\n";
          pause();
          clear_screen();

        break;

      case '2':
          efeito2(palavra);
          cout<<"\n";
          pause();
          clear_screen();
        break;

      case '3':
        efeito3(palavra);
        cout<<"\n";
        pause();
        clear_screen();
        break;

      case '4':
        efeito4(palavra);
        cout<<"\n";
        pause();
        clear_screen();
        break;

      case '5':
          efeito5(palavra);
          cout<<"\n";
          pause();
          clear_screen();
        break;

      case '6':
          efeito6(palavra,veloEfeito6);
          cout<<"\n";
          pause();
          clear_screen();
        break;
      case 'T':
          cout << "  Diagonal Esquerda \n";
          efeito1(palavra);
          pause();
          clear_screen();
          cout << "\n Diagonal Esquerda, Texto Invertido \n";
          efeito2(palavra);
          pause();
          clear_screen();
          cout << "\n Diagonais Cruzadas \n";
          efeito3(palavra);
          pause();
          clear_screen();
          cout << "\n Diagonal Direita, Palavras por Ordem Inversa \n";
          efeito4(palavra);
          pause();
          clear_screen();
          cout << "\n Em V   \n";
          efeito5(palavra);
          pause();
          clear_screen();
          cout << "\n Deslizante  \n";
          efeito6(palavra,veloEfeito6);
          break;

      default:
            cout << "Opcao invalida. Por favor, escolha uma opcao valida.\n" << endl;
            pause();
            clear_screen();
      }
    }
    return 0;
    }
