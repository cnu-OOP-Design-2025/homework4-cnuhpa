#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students] = Student(name, id, midterm, final);
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    for (int i = idx; i < num_of_students; i++) {
        students[i] = students[i+1];
    }
    students[num_of_students] = Student("", 0, 0.0f, 0.0f);
    num_of_students--;
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getID() == student.getID()) {
            students[i] = student;
        }
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getID() == id) {
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    int beststuidx = -1;
    int bestmid = -1;
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > bestmid) {
            beststuidx = students[i].getID();
            bestmid = students[i].getRecord().getMidterm();
        }
    }
    if (bestmid > -1) {
        return beststuidx;
    }
    return -1;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    int beststuidx = -1;
    int bestfinal = -1;
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getRecord().getFinal() > bestfinal) {
            beststuidx = students[i].getID();
            bestfinal = students[i].getRecord().getFinal();
        }
    }
    if (bestfinal > -1) {
        return beststuidx;
    }
    return -1;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    int beststuidx = -1;
    int besttotal = -1;
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getRecord().getTotal() > besttotal) {
            beststuidx = students[i].getID();
            besttotal = students[i].getRecord().getTotal();
        }
    }
    if (besttotal > -1) {
        return beststuidx;
    }
    return -1;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float midsum = 0.0f;
    for (int i = 0; i < num_of_students; i++) {
        midsum += students[i].getRecord().getMidterm();
    }
    if (midsum > 0) {
        return (midsum / num_of_students);
    }
    return 0.0f;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float finalsum = 0.0f;
    for (int i = 0; i < num_of_students; i++) {
        finalsum += students[i].getRecord().getFinal();
    }
    if (finalsum > 0) {
        return (finalsum / num_of_students);
    }
    return 0.0f;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float totalsum = 0.0f;
    for (int i = 0; i < num_of_students; i++) {
        totalsum += students[i].getRecord().getMidterm() + students[i].getRecord().getFinal();
    }
    if (totalsum > 0) {
        return (totalsum / num_of_students);
    }
    return 0.0f;
}

