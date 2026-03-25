function verificar() {
    var data = new Date()
    var ano = data.getFullYear()
    var formulario_ano = document.getElementById('txtano')
    var res = document.getElementById('res')
    
    
    if ((formulario_ano.value.length == 0 || Number(formulario_ano.value) > ano)) {
        window.alert("ERRO! confira os dados inseridos.")
    } 
    else {
        var formulario_sex = document.getElementsByName('radsex')
        var idade = ano - Number(formulario_ano.value)
        var genero = ''
        var img = document.createElement('img')
        img.setAttribute('id','foto')
        
        if (formulario_sex[0].checked) {
            genero = 'Masculino'
            if (idade >= 0 && idade < 4) {
                img.setAttribute('src', 'imagens/homem_bebe.jpg')
            }
            else if (idade < 13) {
                img.setAttribute('src', 'imagens/homem_crianca.jpg')
            }
            else if (idade < 18) {
                img.setAttribute('src', 'imagens/homem_jovem.jpg')
            }
            else if (idade < 60) {
                img.setAttribute('src', 'imagens/homem_adulto.jpg')
            }
            else {
                img.setAttribute('src', 'imagens/homem_idoso.jpg')
            }
        }
        else{
            genero = 'Feminino'
            if (idade >= 0 && idade < 4) {
                img.setAttribute('src', 'imagens/mulher_bebe.jpg')
            }
            else if (idade < 13) {
                img.setAttribute('src', 'imagens/mulher_crianca.jpg')
            } 
            else if (idade < 18) {
                img.setAttribute('src', 'imagens/mulher_jovem.jpg')
            }
            else if (idade < 60) {
                img.setAttribute('src', 'imagens/mulher_adulta.jpg')
            }
            else {
                img.setAttribute('src', 'imagens/mulher_idosa.jpg')
            }
        }
        res.style.textAlign = 'center'
        res.innerHTML = `Idade: ${idade}, Sexo: ${genero} <br><br>`
        res.appendChild(img)
    }


}