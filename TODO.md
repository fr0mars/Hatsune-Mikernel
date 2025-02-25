
# Ouais miku Ouais

## Syscall hooking 

- rewrite genre open, read, kill
on peut deja redirect vers le c2 et aussi bloquer les syscall pour certains fichiers etc

- Implem de la logique conditionnelle genre hook que pour un user 


## C2 

/!\ Network kernel level , potentiellement chiant (pas mon probleme mdrr)

- basiquement tout le "front" du module pour declencher les commandes

ex : 
- status : nous renvoie les process actifs, la ram consommee, la batterie et tout
- kill avec un pid : kill le process
- pull : envoie un fichier depuis la machine cible
- reflechir apres

## Stealth 


 Pas trop trop d'inspi la dessus pour l'instant

 - D'apres un collegue on peut remove un module de la liste des modules en memoire apres l'avoir load tout en le gardant actif
 - virer les kernel logs ?


##  Obfusctation

 - Restez branches



## Persistence

- Idee : foutre un script user space dans un cronjob qui reload le module
