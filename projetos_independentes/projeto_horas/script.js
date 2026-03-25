function carregar(){
    var msg = window.document.getElementById("msg")
    var foto = window.document.getElementById("foto")
    var data = new Date()
    var hora = data.getHours()
    var min = data.getMinutes()

    msg.innerHTML = `Agora são ${hora}:${min} horas`

    if (hora === 1 || hora === 0) {
        msg.innerHTML = `Agora é ${hora} hora`
    }

    if ((hora >= 4) && (hora < 12)) {
        msg.innerHTML += `, Bom dia!`
        foto.src = `imagens/manha.jpg`
        document.body.style.background = 'rgb(98, 239, 85)'
    }
    else if ((hora >= 12 ) && (hora <= 18)) {
        msg.innerHTML += `, Boa tarde!`
        foto.src = `imagens/tarde.jpg`
        document.body.style.background = 'rgb(204, 40, 84)'
    }
    else{
        msg.innerHTML += `, Boa noite!`
        foto.src = `imagens/noite.jpg`
    }

}    