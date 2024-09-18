# Snake-C

This project is an implementation of the classic "Snake" game written in C for terminal/command-line environments. The game is based on the fundamental mechanic of a snake moving across the screen, collecting food, and increasing its tail length. The game can be played in two different modes: easy and hard.

### Key Features:

- **Easy Mode**: The snake will wrap around to the other side if it hits a wall, and the game continues.
- **Hard Mode**: The game ends if the snake hits a wall.
- **Tail Mechanic**: The snake’s tail length increases each time it eats food, and the tail follows the snake’s movement.
- **High Score System**: The game records and saves the highest score in a file. The player is notified when a new high score is achieved.
- **Speed Up**: The snake’s speed increases every 5 pieces of food eaten, making the game progressively harder.
- **Direction Controls**: The player can control the snake using the arrow keys on the keyboard.
- **Graphic Enhancements**: Visual elements like color changes are added as the score increases.

### Usage Instructions:

1. When the game starts, select either easy (0) or hard (1) mode.
2. Use the arrow keys to move the snake.
3. Try to collect as much food as possible without hitting the tail or walls to increase the score.
4. The score is continuously displayed on the terminal screen and saved at the end of the game.

### Technical Details:

- **Screen Controls**: The position of the snake and food is adjusted using the `gotoxy` function.
- **Random Food Positioning**: Food is placed randomly on the screen, ensuring it does not overlap with the tail.
- **Score Recording**: Scores are stored in the "rekor.txt" file and updated at the end of each game.

### Platform and Execution:

- This game is developed for Windows devices and can be run using the `snake_game.exe` file.
- Code details are available in the `snake_game.c` file.

---

Bu proje, klasik "Snake" (Yılan) oyununu terminal/komut satırı ortamında oynatmak üzere yazılmış bir C dilinde uygulamadır. Oyun, bir yılanın ekranda hareket edip yemleri topladığı ve kuyruk uzunluğunu artırdığı temel mekaniğe dayanır. Oyun kolay ve zor olmak üzere iki farklı modda oynanabilir.

### Temel Özellikler:

- **Kolay Mod**: Yılan duvarlara çarptığında diğer taraftan geri döner, oyuna devam edilir.
- **Zor Mod**: Yılan duvarlara çarptığında oyun sona erer.
- **Kuyruk Mekaniği**: Yılanın kuyruk uzunluğu her yem yediğinde artar ve yılanın hareketi boyunca kuyruk kendini takip eder.
- **Rekor Sistemi**: Oyun, en yüksek skoru kaydeder ve dosya üzerinde saklar. Yeni bir rekor kırıldığında oyuncuya bildirilir.
- **Hızlanma**: Yılan, her 5 yem yediğinde hızı artar, bu da oyunu giderek zorlaştırır.
- **Yön Kontrolleri**: Oyuncu klavyedeki yön tuşlarını kullanarak yılanı yönlendirebilir.
- **Grafik İyileştirmeleri**: Puan arttıkça renk değişiklikleri gibi görsel öğeler oyuna eklenmiştir.

### Kullanım Talimatları:

1. Oyun başlatıldığında kolay (0) veya zor (1) mod seçimi yapılır.
2. Yön tuşları kullanılarak yılan hareket ettirilir.
3. Yılanın kuyruk kısmına veya duvarlara çarpmadan mümkün olduğunca fazla yem toplanarak skor artırılmaya çalışılır.
4. Skor, terminal ekranında sürekli olarak gösterilir ve oyun sonunda kaydedilir.

### Teknik Detaylar:

- **Ekran Kontrolleri**: `gotoxy` fonksiyonu ile yılanın ve yemin konumu ayarlanır.
- **Rastgele Yem Konumu**: Yem, ekranın içinde rastgele konumlandırılır ve kuyrukla çakışmaması sağlanır.
- **Kayıt Sistemi**: Skorlar "rekor.txt" dosyasında tutulur ve her oyun sonunda güncellenir.

### Platform ve Çalıştırma:

- Bu oyun, **Windows** cihazlar için uygun olarak geliştirilmiştir ve `snake_game.exe` dosyasıyla çalıştırılabilir.
- Kod detayları, `snake_game.c` dosyasında bulunmaktadır.

Bu oyun, terminal ortamında keyifli bir yılan oyunu deneyimi sunmakta ve oyun içi hız ve puan mekanikleri ile oyuncuya giderek zorlaşan bir deneyim yaşatmaktadır.

This project is a snake game programmed in C.
