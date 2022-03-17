class FileSystem {
    public int timeout;

    Deque<Integer> deque = new ArrayDeque<>();
    List<Integer> isOk = new ArrayList<>();
    Map<Integer, File> map = new HashMap<>();

    public FileSystem(int timeout) {
        this.timeout = timeout;
    }

    public boolean request(int time, int fileId, int number) {
        update(time);
        if (deque.contains(fileId)) {
            return false;
        }

        deque.offer(fileId);
        map.put(fileId, new File(fileId, time, number, false, new HashMap<>()));
        return true;
    }

    public int receive(int time, int fileId, int partId) {
        if (!deque.contains(fileId)) {
            return -1;
        }

        if (map.get(fileId).time + timeout < time) {
            return -1;
        }

        // 包含分块
        if (!map.get(fileId).part.containsKey(partId)) {
            map.get(fileId).part.put(partId, 1);
            update(time);
            return map.get(fileId).number - map.get(fileId).part.size();
        } else {
            return -1;
        }
    }

    public int query(int time) {
        update(time);
        return isOk.size();
    }

    public void update(int time) {
        // 判断文件收包是否有效
        while (deque.size() > 0) { // map对象未被移除
            if (map.get(deque.peekFirst()).time + timeout > time && map.get(deque.peekFirst()).part.size() < map.get(deque.peekFirst()).number) {
                break;
            }

            if (map.get(deque.peekFirst()).time + timeout >= time && map.get(deque.peekFirst()).part.size() == map.get(deque.peekFirst()).number) {
                // ready
                isOk.add(deque.peekFirst());
                deque.pollFirst();
            } else if (map.get(deque.peekFirst()).time + timeout < time) {
                // 超时
                int oritime = map.get(deque.peekFirst()).time;
                int number = map.get(deque.peekFirst()).number;

                Map<Integer, Integer> part = map.get(deque.peekFirst()).part;
                map.put(deque.peekFirst(), new File(deque.peekFirst(), oritime, number, true, part));

                deque.pollFirst();
            } else if (map.get(deque.peekFirst()).time + timeout == time && map.get(deque.peekFirst()).part.size() < map.get(deque.peekFirst()).number) {
                // 超时
                int oritime = map.get(deque.peekFirst()).time;
                int number = map.get(deque.peekFirst()).number;

                Map<Integer, Integer> part = map.get(deque.peekFirst()).part;
                map.put(deque.peekFirst(), new File(deque.peekFirst(), oritime, number, true, part));

                deque.pollFirst();
            }
        }
    }

    public class File {
        public int field;
        public int time;
        public int number;
        public boolean isDelay;
        public Map<Integer, Integer> part;

        public File(int field, int time, int number, boolean isDelay, Map<Integer, Integer> part) {
            this.field = field;
            this.time = time;
            this.number = number;
            this.part = part;
            this.isDelay = isDelay;
        }
    }
