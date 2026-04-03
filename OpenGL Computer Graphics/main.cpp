#include <GL/glut.h>
#include <math.h>

// Variabel transformasi agar bisa dimanipulasi
float scale = 1.0f;       // untuk mengubah ukuran
float rotation = 0.0f;    // untuk rotasi
float translateX = 0.0f;  // translasi X
float translateY = 0.0f;  // translasi Y

void drawCircle(float x, float y, float radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * M_PI * float(i) / float(segments);
        float dx = radius * cosf(angle);
        float dy = radius * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

// Fungsi menggambar rumah
void drawHouse() {
    glPushMatrix();

    // Terapkan transformasi skala, rotasi, dan translasi
    glTranslatef(translateX, translateY, 0);
    glScalef(scale, scale, 1.0f);
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);

    // --- Gambar Dinding Rumah (Persegi panjang) ---
    glColor3f(0.6f, 0.4f, 0.2f); // coklat
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f); // bawah kiri
        glVertex2f(0.5f, -0.5f); // bawah kanan
        glVertex2f(0.5f, 0.0f); // atas kanan
        glVertex2f(-0.5f, 0.0f); // atas kiri
    glEnd();

    // --- Gambar Atap Rumah (Segitiga) ---
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(0.0f, 0.6f);
        glVertex2f(0.6f, 0.0f);
    glEnd();

    // --- Pintu (Persegi panjang kecil) ---
    glColor3f(0.3f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.5f);
        glVertex2f(0.1f, -0.5f);
        glVertex2f(0.1f, -0.2f);
        glVertex2f(-0.1f, -0.2f);
    glEnd();

    // --- Jendela (Persegi) ---
    glColor3f(0.8f, 0.9f, 1.0f); // biru muda
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.25f);
        glVertex2f(-0.2f, -0.25f);
        glVertex2f(-0.2f, -0.05f);
        glVertex2f(-0.4f, -0.05f);
    glEnd();

    // --- Matahari (Lingkaran) ---
    glColor3f(1.0f, 1.0f, 0.0f); // kuning
    drawCircle(0.7f, 0.7f, 0.1f, 100);

    glPopMatrix();
}

// Fungsi tampilan
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawHouse();
    glFlush();
}

// Fungsi untuk handle challenge (misalnya via keyboard)
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': scale += 0.1f; break;     // Perbesar
        case 'S': scale -= 0.1f; break;     // Perkecil
        case 'r': rotation += 10.0f; break; // Rotasi searah jarum jam
        case 'R': rotation -= 10.0f; break; // Rotasi berlawanan arah
        case 'x': translateX += 0.1f; break;
        case 'X': translateX -= 0.1f; break;
        case 'y': translateY += 0.1f; break;
        case 'Y': translateY -= 0.1f; break;
    }
    glutPostRedisplay();
}

// Inisialisasi tampilan
void init() {
    glClearColor(0.5f, 0.8f, 0.92f, 1.0f); // langit biru
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Koordinat 2D
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rumah dengan Bentuk Dasar - OpenGL C++");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}



