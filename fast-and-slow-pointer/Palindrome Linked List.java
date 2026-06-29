class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head, slow = head;
        
        // 1. Find the middle of the linked list
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        
        // 2. Reverse the second half
        ListNode prev = null;
        while (slow != null) {
            ListNode temp = slow.next;
            slow.next = prev;
            prev = slow;
            slow = temp;
        }
        
        // 3. Check for palindrome
        ListNode left = head;
        ListNode right = prev;
        while (right != null) {
            if (left.val != right.val) {
                return false;
            }
            left = left.next;
            right = right.next;
        }
        return true;
    }
}
