<?xml version="1.0" ?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" >
<xsl:output method="html" media-type="text/html; charset=UTF-8"/>

<xsl:variable name="document_visites" select="document('data.xml')"/>

<xsl:template match="/">

	<!-- Generation du fichier index.html - Projections triées par titre de film -->
	<xsl:result-document method="html" href="index.html" >
		<html>
			<head>
				<xsl:call-template name="entete_html"/>
			</head>
			<body>
				<xsl:call-template name="menu" />
				<xsl:apply-templates select="projections" mode="organisee_par_titre"/>
				<xsl:call-template name="pied_de_page" />
			</body>
		</html>
	</xsl:result-document>

	<!-- Generation du fichier projections_par_date.html - Projections triées par date -->    
    <xsl:result-document method="html" href="projections_par_date.html" >
        <html>
            <head>
                <xsl:call-template name="entete_html"/>
            </head>
            <body> 
                <xsl:call-template name="menu" />
                <xsl:apply-templates select="projections" mode="organisee_par_date"/>
                <xsl:call-template name="pied_de_page" />
            </body>
        </html>
    </xsl:result-document>
    
    <!-- Generation du fichier projections_par_classement.html - Projections triées par classement -->    
    <xsl:result-document method="html" href="projections_par_classement.html" >
        <html>
            <head>
                <xsl:call-template name="entete_html"/>
            </head>
            <body> 
                <xsl:call-template name="menu" />
                <xsl:apply-templates select="projections" mode="organisee_par_classement"/>
                <xsl:call-template name="pied_de_page" />
            </body>
        </html>
    </xsl:result-document>
    
    <!-- Generation du fichier liste_des_films.html -->    
    <xsl:result-document method="html" href="liste_des_films.html" >
        <html>
            <head>
                <xsl:call-template name="entete_html"/>
            </head>
            <body>
                <xsl:call-template name="menu" />
                <xsl:call-template name="liste_des_films"/>
                <xsl:call-template name="pied_de_page" />
            </body>
        </html>
    </xsl:result-document>
    
    <!-- Generation des fichiers de film -->    
    <xsl:for-each select="//film[not( preceding::film/titre = titre)]">
        <xsl:variable name="titre_du_film" select="translate(titre, translate(titre, $allowedChars, ''), '')" />
        <xsl:result-document method="html" href="film_{$titre_du_film}.html" >
            <html>
                <head>
                    <xsl:call-template name="entete_html"/>
                </head>
                <body>
                    <xsl:call-template name="menu" />
                    <xsl:apply-templates select="." mode="detail"/>
                    <xsl:call-template name="pied_de_page" />
                </body>
            </html>
        </xsl:result-document>
    </xsl:for-each>
    
    <!-- Generation du fichier liste_des_acteurs.html -->    
    <xsl:result-document method="html" href="liste_des_acteurs.html" >
        <html>
            <head>
                <xsl:call-template name="entete_html"/>
            </head>
            <body>
                <xsl:call-template name="menu" />
                <xsl:call-template name="liste_des_acteurs"/>
                <xsl:call-template name="pied_de_page" />
            </body>
        </html>
    </xsl:result-document>
    
    <!-- Generation des fichiers des acteurs -->    
    <xsl:for-each select="//acteur[not( preceding::acteur/nom = nom)]">
        <xsl:variable name="nom_acteur" select="translate(nom, translate(nom, $allowedChars, ''), '')" />
        <xsl:result-document method="html" href="acteur_{$nom_acteur}.html" >
            <html>
                <head>
                    <xsl:call-template name="entete_html"/>
                </head>
                <body>
                    <xsl:call-template name="menu" />
                    <xsl:apply-templates select="." mode="detail"/>
                    <xsl:call-template name="pied_de_page" />
                </body>
            </html>
        </xsl:result-document>
    </xsl:for-each>

</xsl:template>

<!-- Caractères autoriés dans les url -->  
<xsl:variable name="allowedChars" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'"/>

<!-- Entête html -->  
<xsl:template name="entete_html">
    <title>Listes des projections</title>
    <style type="text/css">
        @import url("./css/style.css");
    </style>
</xsl:template>

<!-- Menus principaux -->   
<xsl:template name="menu">
    <a href="index.html">Projections par titre de film</a>
    <a href="projections_par_date.html">Projections par date</a> 
    <a href="projections_par_classement.html">Projections par classement</a> 
</xsl:template>

<!-- Pied de page du document -->   
<xsl:template name="pied_de_page">
    <br/>
    <br/>
    <a href="liste_des_films.html">Liste des films</a>
    <xsl:text> </xsl:text>
    <a href="liste_des_acteurs.html">Liste des acteurs</a> 
</xsl:template>


<!-- //////////////////////////////////////////////////////////////////////////////////// FILMS /////////////////////////////////////////////////////////////////////////////////////////////////// -->

<!-- Liste de tous les films des projections -->   
<xsl:template name="liste_des_films">
    <h1>Liste des films</h1>
    <xsl:for-each select="//film[not( preceding::film/titre = titre)]">
        <xsl:sort order="ascending" select="titre"/>
        <xsl:apply-templates select="." mode="liste"/>
    </xsl:for-each>
</xsl:template>

<!-- Affichage d'une ligne de la liste des films -->   
<xsl:template match="film" mode="liste">
    <xsl:variable name="titre_du_film" select="translate(titre, translate(titre, $allowedChars, ''), '')" />    
    <li>
        <b>
            <a href="film_{$titre_du_film}.html">
				<span>
					<xsl:if test="photo">
						<xsl:variable name="photo_du_film" select="photo" />
						<img alt="photo_du_film" src="resources/{$photo_du_film}"/>
						<br/>
					</xsl:if>
					 <xsl:value-of select="titre"/>
				</span>
            </a>
        </b>
        <br/>
        <br/>
    </li>
</xsl:template>

<!-- Fiche détaillée d'un film -->   
<xsl:template match="film" mode="detail">
    <h1><xsl:value-of select="titre"/> </h1>
	<xsl:if test="photo">
		<span>
			<xsl:variable name="photo_du_film" select="photo" />
			<img alt="photo_du_film" src="resources/{$photo_du_film}"/>
		</span>
	</xsl:if>
	<span>
		<xsl:if test="duree">
			<p>
				Duree 
				<strong>
					<xsl:if test="not(duree &lt; 60)"><xsl:value-of select="floor(duree div 60)"/>h <xsl:value-of select="duree mod 60"/>min</xsl:if>
					<xsl:if test="duree &lt; 60"><xsl:value-of select="duree"/>min</xsl:if>
					</strong>
				</p>
		</xsl:if>
		<xsl:if test=".//acteur">
			<p>
				Avec
				<strong>
					<xsl:apply-templates select=".//role">
						<xsl:sort order="ascending" select="place" data-type="number" />
						<xsl:sort order="ascending" select=".//nom" />
					</xsl:apply-templates>
					<xsl:if test="count(.//acteur) &gt; 3"> <a href="#acteurs">Plus</a></xsl:if>
				 </strong>
			</p>
		</xsl:if>
		<xsl:if test=".//genre">
			<p>
				Genres 
				 <strong>
					<xsl:for-each select=".//genre">
						<xsl:value-of select="."/>
						<xsl:if test="position() &lt; count(..//genre)">, </xsl:if>
					</xsl:for-each>
				 </strong>
			</p>
		</xsl:if>
		<xsl:if test=".//langage">
			<p>
				Langues 
				 <strong>
					<xsl:for-each select=".//langage">
						<xsl:value-of select="."/>
						<xsl:if test="position() &lt; count(..//langage)">, </xsl:if>
					</xsl:for-each>
				 </strong>
			</p>
		</xsl:if>
	</span>
	<xsl:if test="synopsis">
		<div>
			<h2>Synopsis</h2>
			<p><xsl:value-of select="synopsis"/></p>
		</div>
	</xsl:if>
	
	<!-- Projections du film -->   
	<h2>Projections</h2>
	<ul>
		<xsl:variable name="titre_du_film" select="titre" />
		<xsl:for-each select="//projection[film[titre = $titre_du_film]]">
			<xsl:sort order="ascending" select="date"/>
			<li>
				<b>
					<strong><xsl:value-of select="substring(date,9,2)"/>.<xsl:value-of select="substring(date,6,2)"/>.<xsl:value-of select="substring(date,1,4)"/>
					<xsl:text> </xsl:text><xsl:value-of select="substring(date,12,2)"/>:<xsl:copy-of select="substring(date,15,2)"/></strong>, 
					<xsl:value-of select="noSalle"/>
				</b>
				<br/>
				<br/>
			</li>
		</xsl:for-each>
	</ul>
	
	<!-- acteurs du film -->  
	<xsl:if test=".//acteur">
		<a name="acteurs"/>
		<h2>Acteurs</h2>
		<ul class="list">
			<li class="listItemLabel">
				<span class="listItemElement name">Nom</span>
				<span class="listItemElement birth">Date de naissance</span>
				<span class="listItemElement sex">Sexe</span>
				<span class="listItemElement play">Personnage</span>
			</li>
			<xsl:for-each select=".//acteur">
				<xsl:sort order="ascending" select="../place" data-type="number" />
				<xsl:sort order="ascending" select="nom" data-type="number" />
				<li class="listItem">
					<xsl:apply-templates select="." mode="tableau"/>
					<span class="listItemElement play">
						<xsl:if test="../personnage"><xsl:value-of select="../personnage"/></xsl:if>
						<xsl:if test="not(../personnage)">-</xsl:if>
					</span>
				</li>
			</xsl:for-each>
		</ul>
	</xsl:if>
	
	<!-- critiques du film -->  
	<xsl:if test=".//critiques">
		<div>
			<h2>Critiques</h2>
			<xsl:if test=".//note">
				<h3>Note moyenne <strong><xsl:value-of select="avg(.//note)" /> / 5</strong></h3>
			</xsl:if>
			<xsl:for-each select=".//critique/texte">
				<xsl:if test="../note">
					<h4>Note <strong><xsl:value-of select="../note" /></strong></h4>
				</xsl:if>
				<p><xsl:value-of select="." /></p>
			</xsl:for-each>
		</div>
	</xsl:if>
	
	<!-- Mots clés -->  
	<xsl:if test=".//motCle">
		<div>
			<h2>Mots-clés</h2>
			<p class="keywords">
				<xsl:for-each select=".//motCle">
					<xsl:value-of select="."/>
					<xsl:if test="position() &lt; count(..//motCle)">, </xsl:if>
				</xsl:for-each>
			</p>
		</div>
	</xsl:if>
</xsl:template>

<!-- Affichage des 3 premiers rôles du film -->   
<xsl:template match="role">
	<xsl:if test="not(position() > 3)">
		<xsl:value-of select="replace(.//nom, ',', '')"/>
		<xsl:if test="position() &lt; count(..//acteur)">, </xsl:if>
	</xsl:if>
</xsl:template>


<!-- //////////////////////////////////////////////////////////////////////////////////// ACTEURS /////////////////////////////////////////////////////////////////////////////////////////////////// -->

<!-- Liste de tous les acteurs des films projetés -->   
<xsl:template name="liste_des_acteurs">
    <h1>Liste des acteurs</h1>
    <ul class="list">
		<li class="listItemLabel">
			<span class="listItemElement name">Nom</span>
			<span class="listItemElement birth">Date de naissance</span>
			<span class="listItemElement sex">Sexe</span>
		</li>
		<xsl:for-each select=".//acteur[not( preceding::acteur/nom = nom)]">
			<xsl:sort order="ascending" select="nom"/>
			<li class="listItem">
				<xsl:apply-templates select="." mode="tableau"/>
			</li>
		</xsl:for-each>
	</ul>
</xsl:template>

<!-- Ligne du tableau des acteurs -->   
<xsl:template match="acteur" mode="tableau">
    <xsl:variable name="nom_acteur" select="translate(nom, translate(nom, $allowedChars, ''), '')" />
	<span class="listItemElement name">
		<a href="acteur_{$nom_acteur}.html">
		<xsl:value-of select="nom"/>
	</a>
	</span>
	<span class="listItemElement birth">
		<xsl:if test="dateNaissance">
			<xsl:value-of select="substring(dateNaissance,9,2)"/>.<xsl:value-of select="substring(dateNaissance,6,2)"/>.<xsl:value-of select="substring(dateNaissance,1,4)"/>
		</xsl:if>
		<xsl:if test="not(dateNaissance)">-</xsl:if>
	</span>
	<span class="listItemElement sex">
		<xsl:if test="sexe"><xsl:value-of select="sexe/@valeur"/></xsl:if>
		<xsl:if test="not(sexe)">-</xsl:if>
	</span>
</xsl:template>

<!-- Fiche détaillée d'un acteur -->   
<xsl:template match="acteur" mode="detail">
    <h1><xsl:value-of select="nom"/></h1>
    <table cellspacing="10">
        <tbody>
			<xsl:if test="nomNaissance">
				<tr>
					<td>Nom de naissance</td><td><strong><xsl:value-of select="nomNaissance"/></strong></td>
				</tr>
			</xsl:if>
			<xsl:if test="sexe">
				<tr>
				<td>Sexe</td><td><strong><xsl:value-of select="sexe/@valeur"/></strong></td>
				</tr>
			</xsl:if>
			<xsl:if test="dateNaissance">
				<tr>
					<td>Date de naissance</td>
					<td>
						<strong>
							<xsl:value-of select="substring(dateNaissance,9,2)"/>.<xsl:value-of select="substring(dateNaissance,6,2)"/>.<xsl:value-of select="substring(dateNaissance,1,4)"/>
						</strong>
					</td>
				</tr>
			</xsl:if>
			<xsl:if test="dateDeces">
				<tr>
					<td>Date de décès</td>
					<td>
						<strong>
							<xsl:value-of select="substring(dateDeces,9,2)"/>.<xsl:value-of select="substring(dateDeces,6,2)"/>.<xsl:value-of select="substring(dateDeces,1,4)"/>
						</strong>
					</td>
				</tr>
			</xsl:if>
        </tbody>
    </table>
    <xsl:if test="biographie">
		<div>
			<h2>Biographie</h2>
			<p><xsl:value-of select="biographie"/></p>
		</div>
	</xsl:if>
	
	<!-- Films de l'acteur à l'affiche -->   
	<h2>Films à l'affiche</h2>
	<ul>
		<xsl:variable name="nom_acteur" select="nom" />
		<xsl:for-each select="//film[not( preceding::film/titre = titre)][.//acteur[nom = $nom_acteur]]">
			<xsl:sort order="ascending" select="titre"/>
			<xsl:variable name="titre_du_film" select="titre" />
			<li>
				<b>
					<a href="film_{translate(titre, translate(titre, $allowedChars, ''), '')}.html">
						<xsl:value-of select="titre"/>
					</a>
					<xsl:if test="//film[not( preceding::film/titre = titre)][titre = $titre_du_film]//role[.//acteur[nom = $nom_acteur]]/personnage">
						<xsl:text>, </xsl:text><xsl:value-of select="//film[not( preceding::film/titre = titre)][titre = $titre_du_film]//role[.//acteur[nom = $nom_acteur]]/personnage"/>
					</xsl:if>
				</b>
				<br/>
				<br/>
			</li>
		</xsl:for-each>
	</ul>

</xsl:template>

<!-- //////////////////////////////////////////////////////////////////////////////////// PROJECTIONS /////////////////////////////////////////////////////////////////////////////////////////////////// -->

<!-- Entete du tableau contenant les projections -->   
<xsl:template name="entete_tableau">
	<li class="listItemLabel">
		<span class="listItemElement titre">Film</span>
		<span class="listItemElement date">Date</span>
		<span class="listItemElement salle">Salle</span>
		<span class="listItemElement grade">Classement</span>
	</li>
</xsl:template>

<!-- Ligne du tableau des projections -->   
<xsl:template match="projection" mode="tableau">
    <xsl:variable name="titre_du_film" select="translate(film/titre, translate(film/titre, $allowedChars, ''), '')" />
    <li class="listItem">
		<span class="listItemElement titre">
			<a href="film_{$titre_du_film}.html">
				<xsl:if test="film/photo">
					<xsl:variable name="photo_du_film" select="film/photo" />
					<img alt="photo_du_film" src="resources/{$photo_du_film}"/>
				</xsl:if>
				<xsl:value-of select="film/titre"/>
			</a>
		</span>
		<span class="listItemElement date">
			<xsl:value-of select="substring(date,9,2)"/>.<xsl:value-of select="substring(date,6,2)"/>.<xsl:value-of select="substring(date,1,4)"/><xsl:text> </xsl:text>
			<xsl:value-of select="substring(date,12,2)"/>:<xsl:copy-of select="substring(date,15,2)"/>
		</span>
		<span class="listItemElement salle">
			<xsl:value-of select="noSalle"/>
		</span>
		<span class="listItemElement grade">
			<xsl:if test=".//note"><xsl:value-of select="avg(.//note)"/> / 5</xsl:if>
			<xsl:if test="not(.//note)"> - </xsl:if>
		</span>
    </li>
</xsl:template>

<!-- Liste des projections triée par titre de film -->   
<xsl:template match="projections" mode="organisee_par_titre">
    <h1>Projections par titre de film</h1>
    <ul class="list">
		<xsl:call-template name="entete_tableau"/>
		<xsl:for-each select="projection">
			<xsl:sort order="ascending" select="film/titre"/>
			<xsl:apply-templates select="." mode="tableau"/>
		</xsl:for-each>
	</ul>
</xsl:template>

<!-- Liste des projections triée par date de projection -->   
<xsl:template match="projections" mode="organisee_par_date">
    <h1>Projections par date</h1>
    <ul class="list">
		<xsl:call-template name="entete_tableau"/>
		<xsl:for-each select="projection">
			<xsl:sort order="ascending" select="date"/>
			<xsl:sort order="ascending" select="film/titre"/>
			<xsl:apply-templates select="." mode="tableau"/>
		</xsl:for-each>
	</ul>
</xsl:template>

<!-- Liste des projections triée par classement -->   
<xsl:template match="projections" mode="organisee_par_classement">
    <h1>Projections par classement</h1>
    <ul class="list">
		<xsl:call-template name="entete_tableau"/>
		<xsl:for-each select="projection">
			<xsl:sort order="descending" select="avg(.//note)"/>
			<xsl:sort order="ascending" select="film/titre"/>
			<xsl:apply-templates select="." mode="tableau"/>
		</xsl:for-each>
	</ul>
</xsl:template>

</xsl:stylesheet>