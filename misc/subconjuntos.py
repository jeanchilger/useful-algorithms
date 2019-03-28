from math import factorial as fac

def binomial(n, p):
    b = fac(n) // (fac(p) * fac(n-p))
    return b

conj = list(input("conjunto: ")) # string com os elementos do conjunto (sem espaço)
n = len(conj)
subconjuntos = []

for p in range(0, n+1): # p = tamanho dos subconjuntos, varia de 1 a n
    sub = conj[:p] # subconjunto inicial de tamanho p
    subconjuntos.append("".join(sub))

    f = n-p # fator de correcao para os indices de conj com relacao a sub

    b = binomial(n, p) # b = nCp, numero maximo de combinacoes de tamanho p
    for z in range(b-1):

        for a in range(p):
            #descobre ate onde sub e igual ao final do conj
            #trocar letra anterior e fazer uma sequencia a partir dela
            if sub[a:] == conj[a+f:]:
                i = conj.index(sub[a-1]) + 1
                sub[a-1:] = conj[i:i + p+1 - a]
                subconjuntos.append("".join(sub))
                break

        else: #nao e igual ao fim do conj
            sub[-1] = conj[conj.index(sub[-1]) + 1] # avanca uma letra
            subconjuntos.append("".join(sub))

for i in subconjuntos:
    print("".join(i))
