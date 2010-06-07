function dodaj(tmp)
{

	document.getElementById('content').innerHTML = tmp;

}

function format(liczba)
{ 
	liczba=liczba*100; 
	liczba=Math.round(liczba); 
	liczba=liczba/100; 
	liczba = parseFloat(liczba);
	liczba = String(liczba);
	if(liczba.lastIndexOf('.') == -1)
		liczba += '.00';		
	return liczba; 
}

function info(nr)
{
	if(nr==0)
		  tmp = '<div class="post"><h1 class="title">O firmie: </h1>'+
	    '<div class="entry">	<p>Sprzedażą zajmujemy się od 3 mln lat. Sprawdź nas w krajowym rejestrze dłużników</p>	</div></div>';
	if(nr==1)
	  tmp = '<div class="post"><h1 class="title">Dojazd: </h1>'+
	    '<div class="entry">	<p>01-132 Lublin <br /> ul. Nadbystrzycka 32</p>	</div>'+
		  '<div id="pict"><img alt="" src="images/mapa.jpg" /></div></div>';		
	if(nr==2)	tmp = '<div class="post"><h1 class="title">Kontakt: </h1>'+
	    '<div class="entry">	<p>Telefon:  660-066-060 <br />Formularz kontaktowy:'+formularz()+
			'</p></div></div>';
			
	document.getElementById('content').innerHTML = tmp;
}
function formularz()
{
	tmp = '<div><form action="wyslano"><table>'+
	  '<tr><td>Nazwisko: </td><td><input type="text" id="nazwisko" size="19" maxlength="20" name="form" /></td></tr>'+
	  '<tr><td>Treść: </td><td><textarea id="tresc" rows="8" cols="16"></textarea></td></tr>'+
		'<tr><td></td><td><input type="submit" name="wyslij" value="Wyślij" /> <input type="reset" value="Czy¶ć pola" /></td></tr>'+
		'</table></form></div>';
	return tmp;
}