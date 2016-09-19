#ifndef FileSystemWatcher_h
#define FileSystemWatcher_h

#include <stdint.h>
#include <mutex>

#include <rct/rct-config.h>
#include <rct/Map.h>
#include <rct/Path.h>
#include <rct/Set.h>
#include <rct/SignalSlot.h>
#include <rct/Timer.h>

class FileSystemWatcher
{
private:
	void init() {
		//TODO
	}
	void shutdown() {
		//TODO
	}
public:
    struct Options {
        Options()
            : removeDelay(1000)
        {}
        int removeDelay;
    };
    FileSystemWatcher(const Options &option = Options());
    ~FileSystemWatcher();

    bool watch(const Path &path);
    bool unwatch(const Path &path);
    Signal<std::function<void(const Path &)> > &removed() { return mRemoved; }
    Signal<std::function<void(const Path &)> > &added() { return mAdded; }
    Signal<std::function<void(const Path &)> > &modified() { return mModified; }
    void clear();

    std::mutex mMutex;
    Signal<std::function<void(const Path&)> > mRemoved, mModified, mAdded;

    enum Type {
        Add = 0x1,
        Remove = 0x2,
        Modified = 0x4
    };
    void add(Type type, const Path &path)
    {
        switch (type) {
        case Add:
            if (mRemovedPaths.remove(path)) {
                mModifiedPaths.insert(path);
            } else {
                mAddedPaths.insert(path);
            }
            break;
        case Remove:
            if (!mAddedPaths.remove(path))
                mRemovedPaths.insert(path);
            break;
        case Modified:
            mModifiedPaths.insert(path);
            break;
        }
    }
    const Options mOptions;
    Set<Path> mAddedPaths, mRemovedPaths, mModifiedPaths;
    Timer mTimer;
    void processChanges();
    void processChanges(unsigned int types);
};

#endif
