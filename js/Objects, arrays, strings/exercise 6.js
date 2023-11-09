
function urlWorker(url) {
    let protocol = '', domen = '', path = '';

        let i = 0;
        while (url[i] != ':') {
            protocol += url[i];
            i++;
        }
        i+=3;
        for (; url[i] != '/'; i++) {
            domen += url[i];
        }
    

        for (;i < url.length; i++) {
            path += url[i];
        }

        console.log(protocol, domen, path);
}


urlWorker("https://itstep.org/ua/about");
