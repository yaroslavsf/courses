let obj = {
   producer:"p1",
   model:"m1",
   year: 2005,
   averageSpeed: 60,
   alertInfo() {
    alert(`prod:${this.producer}, model:${this.model}, year:${this.year}, averageSpeed:${this.averageSpeed}`)
   },
   alertTime(distance) {    //km
       // 1m/s = 3.6km/h
       //distance in km
       //time in h
       let time = distance / this.averageSpeed;
       let k = time/4;
       k--;
       if (k - Math.trunc(k) != 0)
         k++;
       k = Math.trunc(k);      
       time = time+(k); 
       if (time%1 > 0) {  
         time = 0.6 * (time%1) + Math.trunc(time);
         time = time.toFixed(2);
       }
       alert(`${time-time%1} часов и ${(time%1).toFixed(2) * 100} минут`);

   }
}

obj.alertInfo();
obj.alertTime(360); //km