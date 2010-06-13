<?php
	$username="root";
	$password="";
	$database="sklep";
	
	mysql_connect('localhost',$username,$password);
	define('MYSQL_DEF_ENCODE',"latin2");
	mysql_set_charset(MYSQL_DEF_ENCODE);
	@mysql_select_db($database);
	
	$kategoria=mysql_query("SELECT * FROM Kategoria") or die("Brak bazy danych. Strona wisi.");	
	$iloscKategoria=mysql_numrows($kategoria);


	while($rowKategoria=mysql_fetch_object($kategoria))
	{
		$tmpa = "";
		$tmpb = 
		"<h1 class=title>$rowKategoria->nazwa</h1><br />
		<table id=tabela cellpadding=4 border=1px rules=rows>
			<tr>
				<th>Nazwa</th>
				<th>Opis</th>
				<th>Dostêpno¶æ</th>
				<th>Cena netto</th>
				<th>Cena brutto</th>
				<th>VAT</th>
			</tr>
			<tr></tr>
		";
		
		$pozycja=mysql_query("SELECT * FROM Towar");
		while($rowPozycja=mysql_fetch_object($pozycja))
		{		
		
			$v = 0;
			switch($rowPozycja->vat)
			{
				case 'VAT0': $v=0; break;
				case 'VAT3': $v=3; break;
				case 'VAT7': $v=7; break;
				case 'VAT14': $v=14; break;
				case 'VAT22': $v=22; break;		
				default: $v=99;
			}
			
			if($rowPozycja->idKategorii == $rowKategoria->id)
			{		
				$brutto = round( $rowPozycja->cena+$rowPozycja->cena*($v/100), 2 );
				$tmpa = "$tmpa
					<tr>
						<td>$rowPozycja->nazwa </td>
						<td>$rowPozycja->opis </td>
						<td>$rowPozycja->ilosc </td>
						<td>$rowPozycja->cena z³</td>
						<td>$brutto z³</td>
						<td>$v%</td>
					</tr>
				";
			}
	
		}
		$tmp = "$tmpb$tmpa</table>";
		if($tmpa == '')
			$tmp = "<strong>Brak towarów w kategorii <a class=title>$rowKategoria->nazwa</a>.</strong>";

		echo "<a href='javascript:dodaj(\"$tmp\")'>$rowKategoria->nazwa</a><br />";
	}	

 	mysql_close();
?>
