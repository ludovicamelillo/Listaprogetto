#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void aggiorna() = 0;
    virtual ~Observer() = default;
};

#endif
