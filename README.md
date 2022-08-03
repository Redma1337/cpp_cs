###### Vorraussetzungen
Um das Spiel auszuführen wird SFML 2.5.1 und mingw32 benötigt, es ist jedoch unter cmake-modules bereits eingebunden.

###### Testflow
Für das testen der verschiedenen Bots gibt es einen Benchmark button, welcher dann 100 Spiele dieser Spieler gegeneinander macht und das Ergebnis anzeigt, mehr als 100 ist möglich, muss aber manuell im code eingestellt werden und beansprucht sehr viel Zeit, weswegen wir es zu 100 gesenkt haben.

Um die Gtests auszuführen müssen in der cmake datei einfach die zugehörigen Zeilen auskommentiert werden, diese sind auskommentiert, weil sonst das builden der exe Probleme erzeugte.

###### Taktik des Intelligenten Bots 
Der bot arbeitet um die Zahl 28, jeder Zug den er macht bekommt einen score und solange dieser score unter 28 bleibt wird er weiter Würfeln, sonst gibt er ab. Dabei wird unterschieden ob der Bot einen Läufer setzt oder bewegt und wie weit die Spalte in der Mitte ist (also am längsten). Spalten in der Mitte werden bevorzugt, da sie niedrige scores haben und die Wahrscheinlichkeit ihre Summe zu bilden die höchste ist. Der Bot versucht also jeden Zug eine Summe zu bilden, die er entweder schon hat oder die am nächsten zur Mitte (7) ist.

###### SFML Probleme
SFML hat vor allem mit der Ausrichtung der Textkomponenten manchmal ein paar Probleme, Aufgrund dessen kann es sein, das an vereinzelten Codestellen der Text falsch positioniert ist oder in einer der game ticks immer wieder erstellt wird, da dies das Problem löst.
