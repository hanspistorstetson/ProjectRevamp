class Event < ApplicationRecord
  validates :dateof, presence: true
  has_many :activities
  belongs_to :user
end
