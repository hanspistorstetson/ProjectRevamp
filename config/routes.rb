Rails.application.routes.draw do
  get 'activities/index'

  get 'welcome/index'
  root 'welcome#index'

  get 'welcome/pricing'
  get 'welcome/contact'

  resources :events do
    get 'join' => 'events#join'
    get 'leave' => 'events#leave'
  end

  resources :activities do
    get 'complete' => 'activities#complete'
  end

  devise_scope :user do
    get 'login', to: 'devise/sessions#new'
  end

  devise_scope :user do
    delete 'logout', to: 'devise/sessions#destroy'
  end

  devise_scope :user do
    get 'signup', to: "devise/registrations#new", as: "new_user_registration"
  end

  devise_for :users
  resources :users, :only => [:show]

  get 'qr/new'
  get 'qr/read'

# For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
